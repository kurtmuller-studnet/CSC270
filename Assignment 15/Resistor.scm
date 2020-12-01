; Procedure to get equate the color of the band to a number
(define (band bandColor)
    (cond
        ((eq? bandColor 'black) 0)
        ((eq? bandColor 'brown) 1)
        ((eq? bandColor 'red) 2)
        ((eq? bandColor 'orange) 3)
        ((eq? bandColor 'yellow) 4)
        ((eq? bandColor 'green) 5)
        ((eq? bandColor 'blue) 6)
        ((eq? bandColor 'violet) 7)
        ((eq? bandColor 'grey) 8)
        ((eq? bandColor 'white) 9)
        (else -1)
        )
)

;returns value of color coded bands
(define (resistance colors)
    (if (= (length colors) 4)
        (*
            ;calculate the power of 10
            (expt 10 (band (car (cdr (cdr (cdr colors))))))
            ;add values of 3 colors
            (+
                ;calculate first band
                (* (band (car colors)) 100)
                ;calculate second band
                (* (band (car (cdr colors))) 10)
                ;calculate third band
                (band (car (cdr (cdr colors))))
            )
        )
    )
)
;run this in the terminal
;resistance '(red yellow black red)
