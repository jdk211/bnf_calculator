# bnf_calculator
c++ bnf calculator

bnf - 사칙연산 num oper num

-----------------------------------------------------
bnf - 사칙연산 num oper num oper num

-----------------------------------------------------


-----------------------------------------------------
bnf - 연산자 우선순위, 괄호 처리

digit := '0','1','2','3','4','5','6','7','8','9'
add_oper := '+','-'
mul_oper := '*','/'
number := digit
number := number digit
pri_exp := number 
pri_exp := ( add_exp )
mul_exp := pri_exp 
mul_exp := mul_exp mul_oper pri_exp
add_exp := mul_exp
add_exp := add_exp add_oper mul_exp


c++ 에 맞는...

=============homework===============
sin, cos, log, unary operator
