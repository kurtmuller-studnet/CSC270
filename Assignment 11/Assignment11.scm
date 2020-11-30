#| 
Exercise 2.2.1 questions a,b,c,d

a. -6.699999999999999
b. -110/87
c. 11/8
d. -5040

Exercise 2.2.3 Questions a to o

a. (car . cdr)
b. (this (is silly))
c. (is this silly?)
d. (+ 2 3)
e. (+ 2 3)
f. +
g. (2 3)
h. #<procedure cons>
i. cons
j. 'cons
k. quote
l. 5
m. 5
n. 5
o. 5  

Exercise 2.2.4
(display (car (cdr (car '((a b) (c d))))))
(display (car (car (cdr '((a b) (c d))))))
(display (car ( cdr (car (cdr '((a b) (c d)))))))
|#

(display "Exercise 2.2.1 questions a,b,c,d\n")
(newline)

(display (+ (* 1.2(- 2 (/ 1 3))) -8.7))
(newline)
(display (/ (+ (/ 2 3) (/ 4 9)) (- (/ 5 11) (/ 4 3))))
(newline)
(display (+ 1 (/ 1 (+ 2 (/ 1 (+ 1 (/ 1 2)))))))
(newline)
(display (* 1 -2 3 -4 5 -6 7))
(newline)

(display "Exercise 2.2.3 Questions a to o\n")
(newline)

;I dont know what supposed to be done here
(display (cons 'car 'cdr))
(newline)
(display (list 'this '(is silly)))
(newline)
(display (cons 'is '(this silly?)))
(newline)
(display (quote (+ 2 3)))
(newline)
(display (cons '+ '(2 3)))
(newline)
(display (car '(+ 2 3)))
(newline)
(display (cdr '(+ 2 3)))
(newline) 
;(display (cons))
;This will display #<procedure cons>
(newline)  
(display (quote cons)) 
(newline)
(display (quote (quote cons)))           
(newline)
(display (car (quote (quote cons))))  
(newline)             
(display (+ 2 3))
(newline)
(display (+ '2 '3))
(newline)
(display (+ (car '(2 3)) (car (cdr '(2 3)))))   
(newline)
(display ((car(list + - * /)) 2 3))    

(newline)
(display "Exercise 2.2.4")
(newline)
(display (car (cdr (car '((a b) (c d))))))
(newline)
(display (car (car (cdr '((a b) (c d))))))
(newline)
(display (car ( cdr (car (cdr '((a b) (c d)))))))
(newline)
