#ifndef OBSERVERS_HPP
#define OBSERVERS_HPP

#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <stdint-gcc.h>
#include <stdbool.h>

#include <boost/preprocessor.hpp>

typedef struct {
    //onNext;
    //onCompleted;
    //onError;
    //onSubscribe;
    //onUnsubscribe
} observer;

void start(){

}

//TODO
void timer(int delay){
}

void repeat(){
    while(true){
        return;
    }
}

#define mrange(startValue, itemsNumber) \
static_assert(!( (itemsNumber)<0 ), "assert"); \
range(startValue, itemsNumber) \
//static_assert( (startValue)>(startValue)+(itemsNumber) && (itemsNumber)>(startValue)+(itemsNumber) ); \

void range(intmax_t  startValue, intmax_t itemsNumber){
    while(itemsNumber){
        printf("%li\n", startValue);
        ++startValue;
        --itemsNumber;
    }
}

void just(){

}

void interval(){

}

void from(){

}

void defer(){

}

void create(){

}

//subscribe;
//unsubscribe;
//request;

static struct observable {
  void(*start)();
  void(*timer)(int);
  void(*repeat)();
  void(*range)(intmax_t,intmax_t);
  void(*just)();
  void(*interval)();
  void(*from)();
  void(*defer)();
  void(*create)();
} observable = {.start = &start,
                .timer = &timer,
                .repeat = &repeat,
                .range = &range,
                .just = &just,
                .interval = &interval,
                .from = &from,
                .defer = &defer,
                .create = &create};

//Хранить ли старое значение
// REACT(R/W/RW, type + name + initilizer)
#if REACT_int
    #pragma message "asdasd"
#endif

//горячие холодные коннектабельные
//subscriber / unsubscribe

#define REACT( observableProperties, type, name, initializer ) \
typedef struct { \
    type private_Name; \
    const type*(*get)(void* self); \
    void(*set)(void* self, const type t); \
} REACT__  ## type; \
\
const type* get__ ## type(void* self){ \
    printf("get of REACT__%s was called\n", #type );\
    return &((REACT__ ## type*)self)->private_Name; \
} \
\
void set__ ## set(void* self, const type t){ \
    printf("set of REACT__%s was called\n", #type );\
    ((REACT__ ## type*)self)->private_Name = t; \
} \
\
REACT__ ## type (name) = {.private_Name = (initializer), \
                          .get = get__ ## type, \
                          .set = set__ ## set}; \

//{a+b/c << k}[a,b,c,k]
#define REXPR( code , conversionPoints )

// блокировка рекурсий

//struct {
//    void* buffer;
//    void(*func);
//};
//
//void s(){
//    if(!buffer){
//        (int)nuffer = 12;
//    }
//}

#endif //OBSERVERS_HPP