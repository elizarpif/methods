
x = 0.1 #x - параметр, x in [-1/4,1/4)
right_sum = pow(1-x*4, -5/2)
right_sum = right_sum * 6


i = 1
a0 = 6
left_sum = 6



while abs(right_sum-left_sum)>=pow(10,-10):
    tmp = 4*i+10
    tmp = tmp / (i+1)
    a0 = a0 * tmp * x
    left_sum = left_sum + a0
    print("right_sum=", right_sum, ", left_sum=",left_sum, ", a", i, "=",a0)
    i = i+1

print("i=", i)
