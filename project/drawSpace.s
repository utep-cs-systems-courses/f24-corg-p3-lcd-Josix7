.file "drawSpace.s"
.text

.global drawSpace
.extern screenWidth
.extern screenHeight
.extern COLOR_WHITE

drawSpace:
    ; Arguments: R12 = colStart, R13 = rowStart

    ; Set up the black background
    mov #0, R15               ; x = 0
loop_fill_y:
    mov #0, R14               ; y = 0
loop_fill_x:
    ; Call fillRectangle for the black background
    call #fillRectangle
    inc R15                   ; Increment x
    cmp &screenWidth, R15     ; Check if x < screenWidth
    jl loop_fill_x            ; Loop if x is less than screenWidth

    inc R14                   ; Increment y
    cmp &screenHeight, R14    ; Check if y < screenHeight
    jl loop_fill_y            ; Loop if y is less than screenHeight

    ; Draw stars
    mov #50, R11              ; Number of stars to draw
star_loop:
    call #rand                ; Generate a random number
    and &screenWidth - 1, R15 ; Limit x to screenWidth
    add R12, R15              ; x += colStart

    call #rand                ; Generate another random number
    and &screenHeight - 1, R14 ; Limit y to screenHeight
    add R13, R14              ; y += rowStart

    mov &COLOR_WHITE, R10     ; Set color to white
    call #drawPixel           ; Call drawPixel(x, y, COLOR_WHITE)

    dec R11                   ; Decrement the number of stars
    jnz star_loop             ; Loop until all stars are drawn

    ret                       ; Return from function