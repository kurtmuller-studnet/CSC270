;;Finds the sum of a list
(define sum 
    (lambda (list)
        (apply + list)))

;;Finds the average of a list
(define (average list)
    (/ (sum list) (length list)))

;;A fucntion to aid in finding variance
(define (mean-sqr list)
    (map (lambda (num) (expt (- num (average list)) 2)) list))

;;Finds the variance of a list
(define (variance list)
    (average (mean-sqr list)))    

;;Finds the standard deviation of a list
(define (standard-deviation list)
    (sqrt(variance list)))

(display (standard-deviation '(3 14 15 9 62 64 37)))

(exit)