#include <iostream>
#include "stack.h"
#include<string>
using namespace std;

string postfijo_a_infijo(string expresion,int& result){
    //Presendencias
    string parentesis = "()";
    string multi_div_mod ="*/%";
    string sum_rest ="+-";
    string nums="0123456789";
    string nueva_expresion;
    auto* operadores = new Stack<char>();
    auto* resultado = new Stack<int>();
    for(auto &ch :expresion){
        if (nums.find(ch)!=string::npos){
            nueva_expresion.push_back(ch);
        }
        else if(parentesis.find(ch)!=string::npos){
            if(ch == ')'){
                while(true){
                    nueva_expresion.push_back(operadores->pop());
                    if (parentesis.find(operadores->top())!=string::npos){
                        operadores->pop();
                        break;
                    }
                }
            }
            else{
                operadores->push(ch);
            }
        }
        else if(multi_div_mod.find(ch)!=string::npos){
            if(operadores->isEmpty()){
                operadores->push(ch);
            }
            else{
                if(multi_div_mod.find(operadores->top())!=string::npos){
                    nueva_expresion.push_back(operadores->pop());
                    operadores->push(ch);
                }
                else{
                    operadores->push(ch);
                }
            }
        }
        else if(sum_rest.find(ch)!=string::npos){
            if(operadores->isEmpty()){
                operadores->push(ch);
            }
            else{
                if(sum_rest.find(operadores->top())!=string::npos){
                    nueva_expresion.push_back(operadores->pop());
                    operadores->push(ch);
                }
                else if(multi_div_mod.find(operadores->top())!=string::npos){
                    while(true){
                        nueva_expresion.push_back(operadores->pop());
                        if(operadores->top()==NULL){
                            break;
                        }
                    }
                    operadores->push(ch);
                }
                else{
                    operadores->push(ch);
                }
            }
        }
    }
    while(!operadores->isEmpty()){
        nueva_expresion.push_back(operadores->pop());
    }
    int aux_result=0;
    int ch_to_int=0;
    for(auto &cha :nueva_expresion){
        if (nums.find(cha)!=string::npos){
            ch_to_int=int(cha)-48;
            resultado->push(ch_to_int);
        }
        else{
            switch (cha) {
                case '+':
                    resultado->push(resultado->pop()+resultado->pop());
                    break;
                case '-':
                    aux_result =resultado->pop();
                    resultado->push(resultado->pop()-aux_result);
                    break;
                case '*':
                    aux_result =resultado->pop();
                    aux_result=aux_result*resultado->pop();
                    resultado->push(aux_result);
                    break;
                case '/':
                    aux_result =resultado->pop();
                    aux_result=resultado->pop()/aux_result;
                    resultado->push(aux_result);
                    break;
                case '%':
                    aux_result =resultado->pop();
                    aux_result=resultado->pop()%aux_result;
                    resultado->push(aux_result);
                    break;

            }
        }
    }
    result=resultado->pop();
    return nueva_expresion;
}

int main() {
    int result=0;
    string expresion="(6+2)*3/2+3-2";
    cout<<postfijo_a_infijo(expresion,result)<<"\nEl resultado es "<<result<<endl;
}
