;;Condition statements for the colors in the list
(define (band color)
    (cond ((equal? color 'black)  0)
          ((equal? color 'brown)  1)
          ((equal? color 'red)    2)
          ((equal? color 'orange) 3)
          ((equal? color 'yellow) 4)
          ((equal? color 'green)  5)
          ((equal? color 'blue)   6)
          ((equal? color 'violet) 7)
          ((equal? color 'grey)   8)
          ((equal? color 'white)  9)
          (else -1)))

(define (lastElement list) 
    (car (reverse list)))

(define (resistance list)
    (if (= (length list) 4)
        ;;Takes the last element and get the power to 10
        (* (expt 10 (band (lastElement list))) 
            ;;Finds the color of each band and adds them together
            (+  (* (band (car list)) 100)
                (* (band (car (cdr list))) 10)
                (band (car (cdr (cdr list))))))))

(display (resistance '(red yellow black red)))
(exit)
