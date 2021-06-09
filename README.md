# bnf_calculator
c++ bnf calculator

bnf - 사칙연산 num oper num

--------------------------------------------------

bnf - 사칙연산 num oper num oper num

--------------------------------------------------

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

--------------------------------------------------

bnf 
digit := '0','1','2','3','4','5','6','7','8','9'
add_oper := '+','-'
mul_oper := '*','/'
unary_oper := '+', '-'
number := digit
number := number digit

unary_exp := number
unary_exp := unary_oper add_exp
func_exp := unary_exp
func_exp := sin(add_exp), cos(add_exp), log(add_exp) 
pri_exp :=  func_exp
pri_exp := ( add_exp )
mul_exp := pri_exp 
mul_exp := mul_exp mul_oper pri_exp
add_exp := mul_exp
add_exp := add_exp add_oper mul_exp


=============homework===============

sin, cos, log, unary operator

=======================06/07==========================
bnf 
digit := '0','1','2','3','4','5','6','7','8','9'
add_oper := '+','-'
mul_oper := '*','/'
unary_oper := '+', '-'
number := digit
number := number digit

unary_exp := number //맨 위에함수가 최소단위를 가져간다
unary_exp := unary_oper add_exp //바로 밑에 또는 맨밑에 함수를 가져온다 -(1+2)
func_exp := unary_exp
func_exp := sin(add_exp), cos(add_exp), log(add_exp) 
pri_exp :=  func_exp
pri_exp := ( add_exp )
mul_exp := pri_exp 
mul_exp := mul_exp mul_oper pri_exp
add_exp := mul_exp
add_exp := add_exp add_oper mul_exp

=============homework===============
sin, cos, log, unary operator

hint = sin,cos,log -> pri_exp
unary oper = number

에 규칙 추가?

숙제 -> T.at(), T[] 차이점
operator []는 범위 검사를 하지 않고, 존재하지 않는 요소에 접근할때 정의되지 않은 동작이 발생
.at() 맴버함수는 범위 검사를 수행하고 존재하지 않는 요소에 접근할때 정의된 예외를 발생

decltype() -> 뭘까

string::const_iterator
peek
next
begin 

end -> length() -1, length() 차이.....
(10) [10] (10] -> 배열의 길이에 대한 검색 필요...
() -> 개 
[] -> 폐
(] -> 반폐

이전에 new delete로 객체를 생성 소멸을 했다면
std::unique_ptr<T>를 사용해서 생성과 소멸을 자동으로 관리한다.
std::unique_ptr<calculator> cal = std::make_unique<calculator>();

변수명 앞에 _를 붙이면 컴파일러에 _로 시작하는 예약어들이 많기 때문에 될수있으면 뒤에 붙인다.