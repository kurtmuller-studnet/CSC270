(define sum 
  (lambda (list)
    (apply + list)))


(define (average list)
    (/ (sum list) (length list)))

(display (average '(3 14 15 9 62 64 37)))