# push_swap
+ Create program called "push_swap" that sorts integer received as arguments. <br>
+ Using 2 stacks (stack A & stack B) and sort randum numbers of stack A in ascending order. <br>
+ Using 11 commands (sa, sb, ss, ra, rb, rr, rra, rrb, rrr, pb, pa) but try to use as few as possible. <br>
+ When you run this program, all command is used for sorting must be displayed. <br>

# Steps what I did
1. I've used "Linked list" to store all integer is received as it is easier to modify data structure when you have to rotate numbers.
2. I've chosen "quicksort" algorithm when you receive over 7 randum numbers until 500 randum numbers.
3. Check each argument is digit number or not, if all arguments is valid number, store in stack A using linked list.
4. Check if there is duplicates or not, check if it is sorted alreday or not.
5. Divide it into 3 parts depends on numbers of elements in stack A. If numbers is less than 3, do "small sorting", if numbers is over 3 and less than 6, do midium sorting", else do "big sorting" using quicksort algorithm.
6. In big sorting, basically I keep dividing it into small parts using median as pivot.
   If number is less than pivot, push to stack B otherwise rotate as well as update pivot info.
   if numbers of elements is bigger than 3 in stack B, keep finding pivot, search number is bigger than that pivot push back to A and update pivot info until number of elements in stack B is less than 3
   Do small sorting in stack B, get mark turned to "1", push to A and rotate so we can store sorted numbers at bottom of stack A.
