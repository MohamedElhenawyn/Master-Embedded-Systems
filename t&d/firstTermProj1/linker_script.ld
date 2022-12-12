/*
First Term project
Name: Mohamed Ahmed Mostafa Elhenawy
*/

MEMORY
{
    flash(RX): ORIGIN = 0x08000000 , LENGTH = 128K
    sram(RWX): ORIGIN  =   0x20000000,LENGTH = 20K
}

SECTIONS
{
    .text :
    {
        *(.vectors)
        *(.text)
        *(.rodata)
        _E_text_ = .;
    }>flash
    .data :
    {
        _S_data_ = .;
        *(.data)
        _E_data_ = .;
    }>sram AT>flash
    .bss :
    {
        _S_bss_ = .;
        *(.bss)
        _E_bss_ = .;
    }>sram
}