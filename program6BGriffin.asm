TITLE Combinatorics     (program6BGriffin.asm)

; Author: Stephen Griffin <griffste@oregonstate.edu>
; Course / Project ID  CS271-400 Program 6B            Date: March 13, 2016
; Description: The program generates and displays random combinatorics problems in the range n = [3...12] and r in [1...n], 
;			   prompts the user for an answer, and then lets user know if they are correct or not.
;
;NOTE_1: The program will repeat until the student chooses to quit
;NOTE_2: User's numeric input read as string, validated, then converted to int

INCLUDE Irvine32.inc

; (insert constant definitions here)

LO = 3			;LO and HI provide the range for n
HI = 12		

;Description: Macro for displaying string
;Receives: string label
mWriteStr	MACRO buffer
	push	edx
	mov		edx, OFFSET buffer
	call	WriteString
	pop		edx
ENDM


; (insert variable definitions here)
.data
intro		BYTE	"Hi, my name is Stephen, and I'm here to sort some random integers for you!", 0
prompt_1	BYTE	"What's your name? ", 0
userName	BYTE	33 DUP(0)		;string to be entered by user
hello		BYTE	"Hello ", 0
showp_1		BYTE	"Problem: ", 0
showp_2		BYTE	"Number of elements in the set: ", 0
showp_3		BYTE	"Number of elements to choose from the set: ", 0
prompt_2	BYTE	"How many ways can you choose? ", 0
n			DWORD	?
r			DWORD	?
nminusr		DWORD	?
result		DWORD	?
answer		BYTE	15 DUP(0)			;the string the user's answer will be stored in
finalAns	DWORD	?					;the integer form of the answer
outofRange	BYTE	"Invalid input.", 0
showr_1		BYTE	"There are ", 0
showr_2		BYTE	" combinations of ", 0
showr_3		BYTE	" items from a set of ", 0
period		BYTE	".", 0
incorrect	BYTE	"You are incorrect. You need more practice.", 0
correct		BYTE	"You are correct. Great job!", 0
prompt_3	BYTE	"Would you like another problem? (y/n): ", 0
again		BYTE	10 DUP(0)
goodbye		BYTE	"Good-bye ", 0



.code
main PROC

	call	Randomize				;needed to seed random numbers

	;introduction
	push	OFFSET intro
	push	OFFSET userName
	call	introduction

another:	
	;showProblem
	push	OFFSET n
	push	OFFSET r
	call	showProblem

	;getData
	push	OFFSET finalAns
	push	finalAns
	push	OFFSET answer
	call	getData

	;combinations
	push	n
	push	r
	push	nminusr
	push	OFFSET result
	call	combinations

	;showResults
	push	n
	push	r
	push	result
	push	finalAns
	call	showResults
	
	;ask user if they would like another problem
	;and validate response
tryAgain:
	mov		edx, OFFSET again
	mov		ecx, 10
	mWriteStr	prompt_3
	call	ReadString
	cmp		eax, 1
	jg		invalid
	mov		esi, edx
	lodsb
	cmp		al, 89
	je		yes
	cmp		al, 121
	je		yes
	cmp		al, 78
	je		no
	cmp		al, 110
	je		no
	jmp		invalid

invalid:
	mWriteStr	outOfRange
	call	CrLf
	jmp		tryAgain

yes:
	call	CrLf
	call	CrLf
	jmp		another

no:
	;farewell
	push	OFFSET userName
	push	OFFSET goodbye
	call	farewell

	exit	; exit to operating system
main ENDP


; (insert additional procedures here)

;Description: Introduces programmer and gets user's name
;Receives: intro, prompt_1, userName, hello
;Returns: Message saying hello to user
;Preconditions: N/A
;Registers Changed: eax, ecx, edx, ebp

introduction	PROC
;Introduce programmer
	push	eax
	push	ecx
	push	edx
	push	ebp
	mov		ebp, esp
	
	mWriteStr intro
	call	CrLf

;Get user name
	mWriteStr	prompt_1
	mov		edx, [ebp+20]		;userName
	mov		ecx, 32
	call	ReadString

;Say Hello
	mWriteStr hello
	mov		edx, [ebp+20]		;userName
	call	WriteString
	call	CrLf
	call	CrLf

	pop		ebp
	pop		edx
	pop		ecx
	pop		eax
	ret		4
introduction ENDP


;Description: Displays random combinatorics problem to user
;Receives: OFFSET n, OFFSET r
;Returns: n and r with random values
;Preconditions: N/A
;Registers Changed: eax, ebx, ecx, ebp

showProblem	PROC
	push	eax
	push	ebx
	push	ecx
	push	ebp
	mov		ebp, esp
	
	mWriteStr	showp_1
	call	CrLf
	mWriteStr	showp_2
	mov		eax, HI
	sub		eax, LO
	inc		eax
	call	RandomRange			;to get random n
	add		eax, LO
	call	WriteDec
	mov		ebx, [ebp+24]
	mov		[ebx], eax
	call	CrLf
	mWriteStr	showp_3
	sub		eax, 1
	inc		eax
	call	RandomRange			;to get random r
	add		eax, 1
	mov		ecx, [ebp+20]
	mov		[ecx], eax
	call	WriteDec
	call	CrLf

	pop		ebp
	pop		ecx
	pop		ebx
	pop		eax
	ret 8
showProblem	ENDP


;Description: Gets the user's answer as a string, validates it, and converts it to an int 
;Receives: answer (string), finalAns (int), OFFSET finalAns
;Returns: Integer for finalAns
;Preconditions: N/A
;Registers Changed: al, eax, ebx, ecx, edx, esi, ebp

getData	PROC
	push	eax
	push	ebx
	push	ecx
	push	edx
	push	esi	
	push	ebp
	mov		ebp, esp

reenter:
	mov		edx, [ebp+28]
	mov		ecx, 15
	mWriteStr	prompt_2
	call	ReadString
	cmp		eax, 10			;check if too big for DWORD
	jg		invalid
	mov		ecx, eax		;number of characters in string entered in ecx	
	mov		esi, edx
	mov		ebx, 10
	mov		edx, [ebp+32]
	mov		edx, 0
	cld

convert:	
	mov		eax, edx
	mul		ebx					;multiply by ten
	mov		edx, eax
	xor		eax, eax			;clears eax
	lodsb
	sub		al, 48				;convert from ASCII to decimal
	cmp		al, 0				;check if between 0-9
	jl		invalid
	cmp		al, 9
	jg		invalid
	add		edx, eax			;add to current value
	mov		eax, edx
	loop	convert
	mov		ebx, [ebp+36]		
	mov		[ebx], eax
	jmp		over

invalid:
	mWriteStr	outOfRange
	call	CrLf
	jmp		reenter

over:	
	pop		ebp
	pop		esi
	pop		edx
	pop		ecx
	pop		ebx
	pop		eax
	ret		12
getData	ENDP


;Description: Calculates the combinatorics answer by using factorial for n, r, and (n - r)
;Receives: n, r, nminusr, OFFSET result
;Returns: Integer for result
;Preconditions: N/A
;Registers Changed: eax, ebx, ecx, edx, ebp

combinations PROC
	push	eax
	push	ebx
	push	ecx
	push	edx
	push	ebp
	mov		ebp, esp
	
	;n!
	push	[ebp+36]			
	call	factorial
	mov		ebx, eax

	;r!
	push	[ebp+32]		
	call	factorial	
	mov		ecx, eax		

	;(n-r)!
	mov		eax, [ebp+36]		;n
	mov		edx, [ebp+32]		;r
	sub		eax, edx			;n-r
	mov		[ebp+28], eax		
	push	[ebp+28]
	call	factorial
	mov		edx, eax


	;n!/(r!(n-r)!)
	mov		eax, ecx
	mul		edx					;r!(n-r)!
	mov		edx, 0
	mov		ecx, eax			
	mov		eax, ebx
	call	Crlf
	div		ecx					;n!/(r!(n-r)!)
	mov		ebx, [ebp+24]
	mov		[ebx], eax		

	pop		ebp
	pop		edx
	pop		ecx
	pop		ebx
	pop		eax
	ret		16
combinations ENDP

;Description: Recursively calculates factorial of passed integer
;Receives: Integer (n, r, nminusr)
;Returns: Factorial for pushed variable
;Preconditions: N/A
;Registers Changed: eax, ebx, ebp
;Source: "Assembly Language for x86 Processors" (7th Edition) by Kip Irvine

factorial PROC
	;NOTE:	If eax is pushed and popped here, it affects the returned results
	push	ebx
	push	ebp
	mov		ebp, esp

	mov		eax, [ebp+12]
	cmp		eax, 0				;base case
	ja		L1
	mov		eax, 1
	jmp		L2
L1:								;recursive case
	dec		eax
	push	eax
	call	factorial
		
ReturnFact:						;executed when each recursive call returns
	mov		ebx, [ebp+12]
	mul		ebx

L2:
	pop		ebp
	pop		ebx
	ret		4
factorial ENDP

;Description: Displays correct answer and message to user letting them know if they were correct/incorrect
;Receives: n, r, result, finalAns
;Returns: Message with answer and user evaluation
;Preconditions: N/A
;Registers Changed: eax, ebx

showResults PROC
	push	eax
	push	ebx
	push	ebp
	mov		ebp, esp

	mWriteStr	showr_1
	mov		eax, [ebp+20]		;result
	call	WriteDec
	mWriteStr	showr_2			
	mov		eax, [ebp+24]		;r
	call	WriteDec
	mWriteStr	showr_3
	mov		eax, [ebp+28]		;n
	call	WriteDec
	mWriteStr	period
	call	CrLf
	
	mov		eax, [ebp+16]		
	mov		ebx, [ebp+20]
	cmp		eax, ebx			;compare user's answer with calculated answer
	jne		wrong
right:
	mWriteStr	correct
	call	CrLf
	jmp		done
wrong:
	mWriteStr	incorrect
	call	CrLf
done:
	call	CrLf
	pop		ebp
	pop		ebx
	pop		eax
	ret 16
showResults ENDP

;Description: Farewell message to user indicating program is over
;Receives: goodbye, userName
;Returns: Message saying goodbye to user
;Preconditions: userName must be initalized
;Registers Changed: eax, edx, ebp

farewell	PROC
	push	ebx
	push	ebp
	mov		ebp, esp
	call	CrLf
	mov		edx, [ebp+12]		;goodbye
	call	WriteString
	mov		edx, [ebp+16]		;userName
	call	WriteString
	call	CrLf

	pop		ebp
	pop		ebx
	ret		8
farewell	ENDP


END main



