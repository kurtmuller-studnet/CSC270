#|
For example, a resistor with the first three bands red-yellow-black will have a base value of 240. The fourth band is red, which means that the multiplier is 10^2=100.

Write a program that translates a resistor's color-coding to a value.

For example:
(resistance '(red yellow black red)) 
;Value: 24000

Col    Val
Black 	0
Brown 	1
Red 	2
Orange 	3
Yellow 	4
Green 	5
Blue 	6
Violet 	7
Grey 	8
White 	9
|#

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

(define (lastElement list) 
    (car (reverse list)))

;; can get a specific element of the list with:
;(list-ref '(a b c d e f) 2)

;;Find the sum of a list
;;let x (reverse (cdr (reverse list))))
(define sum 
    (lambda (list)
        (apply + list)))

(define (lastElement list) 
    (car (reverse list)))

(define (resistance list)
    (* (sum list) (expt 10 (lastElement list))))

(define alist (list red yellow black red))

(display (resistance alist)) 
;(display (sum alist))
;Value: 24000