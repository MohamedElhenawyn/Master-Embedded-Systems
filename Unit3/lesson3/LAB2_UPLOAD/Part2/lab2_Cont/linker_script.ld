MEMORY
{
	flash(RX)	: ORIGIN = 0x08000000 , LENGTH = 128K
	sram(RWX)	: ORIGIN = 0x20000000 , LENGTH = 20K
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		_E_text = .;
	}>flash
	.data :
	{
		_S_Data = .;
		*(.data)
		_E_Data = .;
	}>sram AT> flash
	.bss :
	{
		_S_Bss = .;
		*(.bss*)
		. = ALIGN(4);
		_E_bss = .;
		. = ALIGN(4);
		. = . + 0x1000;
		_stack_top = .;
	}>sram
}