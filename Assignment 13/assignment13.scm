;;Sum all of the elements of a list together
(define sum 
  (lambda (list)
    (apply + list)))

;;Finds the average of a list using the sum function
(define (average list)
    (/ (sum list) (length list)))

(display (average '(3 14 15 9 62 64 37)))
(exit)