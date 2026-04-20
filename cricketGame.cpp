#include <chrono>
#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <thread>

enum class Difficulty
{
    Easy = 1,
    Medium = 2,
    Hard = 3
};

class Rng
{
public:
    Rng() : engine(std::random_device{}()) {}

    int uniform(int min, int max)
    {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(engine);
    }

private:
    std::mt19937 engine;
};

class Scoreboard
{
public:
    Scoreboard(int overs, int wickets)
        : runs(0), wickets(0), balls(0), maxBalls(overs * 6), maxWickets(wickets) {}

    void addBall() { ++balls; }
    void addRuns(int r) { runs += r; }
    void addWicket() { ++wickets; }

    bool hasBallsRemaining() const { return balls < maxBalls; }
    bool isAllOut() const { return wickets >= maxWickets; }

    int completedOvers() const { return balls / 6; }
    int ballInOver() const { return balls % 6; }
    int remainingBalls() const { return maxBalls - balls; }

    int totalRuns() const { return runs; }
    int totalWickets() const { return wickets; }
    int totalBalls() const { return balls; }

private:
    int runs;
    int wickets;
    int balls;
    int maxBalls;
    int maxWickets;
};

class Input
{
public:
    static int promptInt(const std::string &message, int min, int max)
    {
        int value;
        while (true)
        {
            std::cout << message;
            if (std::cin >> value && value >= min && value <= max)
            {
                return value;
            }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a number between " << min << " and " << max << ".\n";
        }
    }
};

struct InningsResult
{
    int runs = 0;
    int wickets = 0;
    int balls = 0;
};

class CricketGame
{
public:
    void run()
    {
        greet();
        int overs = Input::promptInt("How many overs per innings? (1-50): ", 1, 50);
        int wickets = Input::promptInt("How many wickets per innings? (1-10): ", 1, 10);
        int difficultyChoice = Input::promptInt("Select difficulty (1 Easy, 2 Medium, 3 Hard): ", 1, 3);

        configOvers = overs;
        configWickets = wickets;
        difficulty = static_cast<Difficulty>(difficultyChoice);

        int userTossChoice = Input::promptInt("Choose your coin side (1 Heads, 2 Tails): ", 1, 2);
        int tossResult = rng.uniform(1, 2);

        bool userWonToss = userTossChoice == tossResult;
        bool userBatsFirst = decideBatFirst(userWonToss);

        if (userBatsFirst)
        {
            auto userInnings = playUserBatting(false, 0, overs, wickets);
            int target = userInnings.runs + 1;
            std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            std::cout << " Target: " << target << "\n";
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

            auto comInnings = playUserBowling(true, target, overs, wickets);
            concludeMatch(userInnings, comInnings);
        }
        else
        {
            auto comInnings = playUserBowling(false, 0, overs, wickets);
            int target = comInnings.runs + 1;
            std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            std::cout << " Target: " << target << "\n";
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

            auto userInnings = playUserBatting(true, target, overs, wickets);
            concludeMatch(userInnings, comInnings);
        }
    }

private:
    void greet()
    {
        std::cout << "Welcome to the Finger Cricket game!\n";
        std::cout << "Pick a number between 1 and 6 while the computer does the same.\n";
        std::cout << "If both match, it is a wicket; otherwise runs are added.\n";
        std::cout << "Batting allows 0 (dot ball); bowling choices are 1-6.\n\n";    }

    bool decideBatFirst(bool userWonToss)
    {
        if (userWonToss)
        {
            std::cout << "You won the toss.\n";
            int choice = Input::promptInt("Bat or bowl first? (1 Bat, 2 Bowl): ", 1, 2);
            return choice == 1;
        }

        int comChoice = rng.uniform(1, 2);
        std::cout << "Computer won the toss and chose to " << (comChoice == 1 ? "bat." : "bowl.") << "\n";
        return comChoice == 1;
    }

    InningsResult playUserBatting(bool chasing, int target, int overs, int wickets)
    {
        Scoreboard sb(overs, wickets);
        while (sb.hasBallsRemaining() && !sb.isAllOut() && (!chasing || sb.totalRuns() < target))
        {
            int userChoice = Input::promptInt("Make your run choice (0-6): ", 0, 6);
            int comChoice = rng.uniform(1, 6);
            bool wicket = isBattingWicket(userChoice, comChoice);

            sb.addBall();
            if (wicket)
            {
                sb.addWicket();
            }
            else
            {
                sb.addRuns(userChoice);
            }

            printBattingScore(sb, "You", chasing, target);
        }

        return {sb.totalRuns(), sb.totalWickets(), sb.totalBalls()};
    }

    InningsResult playUserBowling(bool chasing, int target, int overs, int wickets)
    {
        Scoreboard sb(overs, wickets);
        while (sb.hasBallsRemaining() && !sb.isAllOut() && (!chasing || sb.totalRuns() < target))
        {
            int userChoice = Input::promptInt("Make your bowling choice (1-6): ", 1, 6);
            int comRun = rng.uniform(0, 6);
            bool wicket = userChoice == comRun;

            sb.addBall();
            if (wicket)
            {
                sb.addWicket();
            }
            else
            {
                sb.addRuns(comRun);
            }

            printBattingScore(sb, "Computer", chasing, target);
        }

        return {sb.totalRuns(), sb.totalWickets(), sb.totalBalls()};
    }

    bool isBattingWicket(int userChoice, int comChoice) const
    {
        switch (difficulty)
        {
        case Difficulty::Easy:
            return userChoice == comChoice;
        case Difficulty::Medium:
            return userChoice == comChoice || userChoice + 1 == comChoice;
        case Difficulty::Hard:
            return userChoice == comChoice || userChoice + 1 == comChoice || userChoice - 1 == comChoice;
        default:
            return userChoice == comChoice;
        }
    }

    void printBattingScore(const Scoreboard &sb, const std::string &battingSide, bool chasing, int target)
    {
        int o = sb.completedOvers();
        int b = sb.ballInOver();

        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        std::cout << battingSide << " Score: " << sb.totalRuns() << " - " << sb.totalWickets()
                  << "  overs: " << o << "." << b << "\n";
        if (chasing)
        {
            int remainingRuns = target - sb.totalRuns();
            int remainingBalls = sb.remainingBalls();
            std::cout << "Target: " << target << "\n";
            std::cout << "Need " << remainingRuns << " more runs from " << remainingBalls << " balls.\n";
        }
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    }

    void concludeMatch(const InningsResult &user, const InningsResult &computer)
    {
        std::cout << "\n===================================\n";
        if (user.runs > computer.runs)
        {
            std::cout << "Congratulations! You won the match.\n";
            adviseNextStep(true);
        }
        else if (user.runs < computer.runs)
        {
            std::cout << "Alas! You lost the match.\n";
            adviseNextStep(false);
        }
        else
        {
            std::cout << "Scores are level. Super over begins.\n";
            playSuperOver();
        }
        std::cout << "===================================\n";
    }

    void adviseNextStep(bool userWon)
    {
        if (userWon)
        {
            if (difficulty == Difficulty::Easy)
            {
                std::cout << "Try Medium or Hard difficulty next.\n";
            }
            else if (difficulty == Difficulty::Medium)
            {
                std::cout << "Try Hard difficulty next.\n";
            }
            else
            {
                std::cout << "You're mastering the game. Keep going!\n";
            }
        }
        else
        {
            if (difficulty == Difficulty::Hard)
            {
                std::cout << "Consider Medium or Easy difficulty.\n";
            }
            else if (difficulty == Difficulty::Medium)
            {
                std::cout << "Consider Easy difficulty for a warm-up.\n";
            }
            else
            {
                std::cout << "Maybe take a break and try again.\n";
            }
        }
    }

    void playSuperOver()
    {
        std::cout << "Super over: 1 over, 2 wickets.\n";
        int overs = 1;
        int wickets = 2;

        bool userBatsFirst = rng.uniform(1, 2) == 1;
        if (userBatsFirst)
        {
            auto userInnings = playUserBatting(false, 0, overs, wickets);
            int target = userInnings.runs + 1;
            std::cout << "Super over target for computer: " << target << "\n";
            auto comInnings = playUserBowling(true, target, overs, wickets);
            concludeSuperOver(userInnings, comInnings);
        }
        else
        {
            auto comInnings = playUserBowling(false, 0, overs, wickets);
            int target = comInnings.runs + 1;
            std::cout << "Super over target for you: " << target << "\n";
            auto userInnings = playUserBatting(true, target, overs, wickets);
            concludeSuperOver(userInnings, comInnings);
        }
    }

    void concludeSuperOver(const InningsResult &user, const InningsResult &computer)
    {
        if (user.runs > computer.runs)
        {
            std::cout << "You win the super over and the match!\n";
        }
        else if (user.runs < computer.runs)
        {
            std::cout << "Computer wins the super over.\n";
        }
        else
        {
            std::cout << "Super over tied as well. It's a draw!\n";
        }
    }

    int configOvers = 0;
    int configWickets = 0;
    Difficulty difficulty = Difficulty::Easy;
    Rng rng;
};

int main()
{
    CricketGame game;
    game.run();
    return 0;
}
