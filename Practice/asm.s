	.file	"asm.c"                             # Specifies the name of the source file
	.def	___main;	.scl	2;	.type	32;	.endef # Startup initialization definition for MinGW
	.text                               # Declares that the following is executable code
	.globl	_main                       # Declares '_main' as a global symbol (visible to linker)
	.def	_main;	.scl	2;	.type	32;	.endef # Metadata for the main function
_main:                                  # The entry point label for the main function
LFB10:                                  # Local Function Begin marker
	.cfi_startproc                      # Call Frame Information: starts tracking for stack unwinding
	pushl	%ebp                        # Save the old base pointer on the stack
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp                  # Set base pointer to current stack pointer value (new stack frame)
	.cfi_def_cfa_register 5
	andl	$-16, %esp                  # Align the stack pointer to a 16-byte boundary
	subl	$16, %esp                   # Allocate 16 bytes of space on the stack for local variables
	call	___main                     # Call MinGW initialization routine
	movl	$1, 12(%esp)                # Store immediate value 1 into the stack at esp+12 (e.g., int a = 1;)
	movl	$2, 8(%esp)                 # Store immediate value 2 into the stack at esp+8 (e.g., int b = 2;)
	movl	12(%esp), %edx              # Load local var 'a' (value 1) from esp+12 into register edx
	movl	8(%esp), %eax               # Load local var 'b' (value 2) from esp+8 into register eax
	addl	%edx, %eax                  # Add edx and eax, store result (3) in eax (a + b)
	movl	%eax, 4(%esp)               # Store the sum from eax into stack at esp+4 (e.g., int sum = a + b;)
	movl	4(%esp), %eax               # Load the sum back into eax, which is used for the return value of main
	leave                               # Clean up stack frame (equivalent to: movl %ebp, %esp; popl %ebp)
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret                                 # Return to caller
	.cfi_endproc                        # End of Call Frame tracking
LFE10:                                  # Local Function End marker
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0" # Compiler version metadata
