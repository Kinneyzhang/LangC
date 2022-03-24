;;

(defun rearrange-get-numbers ()
  (let* ((numbers (read-string "Input a list of numbers: "))
         (num-lst (split-string numbers "[ ]+")))
    (unless (= (% (length num-lst) 2) 0)
      (user-error "Last column number is not paired!"))
    num-lst))

(defun rearrange-str ()
  (interactive)
  (let ((num-lst (rearrange-get-numbers))
        (str (read-string "Input string: "))
        res)
    (dotimes (i (/ (length num-lst) 2))
      (let* ((i (* i 2))
             (beg (string-to-number (nth i num-lst)))
             (end (1+ (string-to-number (nth (1+ i) num-lst)))))
        (setq res (concat res (substring str beg end)))))
    (message "%s" res)))

;; 2 6 8 15
;; happy hacking emacs and emacs is a life style.
;; ppy hcking em
