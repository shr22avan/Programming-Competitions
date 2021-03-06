(defun union1 (x y) (cond ((null x) y) ((member (car x) y) (union1 (cdr x) y)) (t (cons (car x) (union1 (cdr x) y)))))

(defun intersection1 (x y) (cond ((null x) nil) ((member (car x) y) (cons (car x) (intersection1 (cdr x) y))) (t (intersection1 (cdr x) y))))

(defun fibo (x y) (let ((a 0) (b 1) (c 1) (d 0)) (loop while (< d y) do (if (/= d 0) (progn (setq c (+ a b)) (setq a b) (setq b c))) (if (>= d x) (print a)) (incf d))))

(defun search1 (x y) (cond ((null x) "Not Found") ((eq (car x) y) "Found") (t (search1 (cdr x) y))))

(defun search2 (x y d) (cond ((consp x) (progn ( if (eq (car x) y) (print d)) (search2 (cdr x) y (+ d 1))))))

(defun lesser (x y) (cond ((null x) nil)  ((<= (car x) y) (cons (car x) (lesser (cdr x) y))) (t (lesser (cdr x) y))))

(defun greater (x y) (cond ((null x) nil) ((> (car x) y) (cons (car x) (greater (cdr x) y))) (t (greater (cdr x) y))))

(defun qsort (x) (cond ((null x) nil) (t (cons (cons (qsort (lesser (cdr x) (car x))) x) (qsort (greater (cdr x) (car x)))))))

(defun qsort (x) (cond ((null x) nil) (t (let ((l (lesser (cdr x) (car x))) (g (greater (cdr x) (car x)))) (cond ((null l) (append (cons (car x) ()) (qsort g)))(t (append (qsort l) (append (cons (car x) ()) (qsort g)))))))))

 (defun flatten (structure)
  (cond ((null structure) nil)
        ((atom structure) `(,structure))
        (t (mapcan #'flatten structure))))

