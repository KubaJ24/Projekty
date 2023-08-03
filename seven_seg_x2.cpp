/*
Biblioteka do wyświetlacza 7 - segmentowego z dwoma modułami zwartymi
*/

Struct Number {
    char num1, num2;
};

typedef struct Number Struct;

Struct num_to_dig(char x){
    Struct number;
    number.num1 = x / 10;
    number.num2 = x % 10;
    return number;
}
