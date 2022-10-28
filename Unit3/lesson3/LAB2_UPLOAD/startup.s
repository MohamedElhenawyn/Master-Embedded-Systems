/*learn-in-depth
Unit3_lab2
Mohamed Elhenawy*/

.section .vectors


.word 0x20001000
.word _reset
.word Vector_handler /*	2 NMI		*/
.word Vector_handler /*	3 Hard_Fault		*/
.word Vector_handler /*	4 MM fault		*/
.word Vector_handler /*	5 bus fault		*/
.word Vector_handler /*	6 usage fault		*/
.word Vector_handler /*	7 reserved		*/
.word Vector_handler /*	8 reserved		*/
.word Vector_handler /*	9 reserved		*/
.word Vector_handler /*	10 reserved		*/
.word Vector_handler /*	11 SV call		*/
.word Vector_handler /*	12 Debug reserved		*/
.word Vector_handler /*	13 reserved		*/
.word Vector_handler /*	14 PendSV		*/
.word Vector_handler /*	15 systick		*/
.word Vector_handler /*	16 IRQ0		*/
.word Vector_handler /*	17 IRQ1		*/
.word Vector_handler /*	18 IRQ2		*/
.word Vector_handler /*	19 ....		*/
		/* On to IRQ67 */

.section .text
_reset:
	bl main
	b .

.thumb_func
Vector_handler:
	b _reset