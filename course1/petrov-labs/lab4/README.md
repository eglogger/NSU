# lab4 - Stack Calculator
    Вход:
            Одна строка длиной не более 1000 символов.
    Выход:
            Eсли на входе выражение, состоящее не только из целых чисел и (, ), +, -, *, /, то "syntax error".
            Eсли на входе выражение, вычисление которого приводит к делению на 0, то "division by zero".
            Иначе - значение выражения.

### Пример 1
    Вход:
        (((((
    Выход:
        syntax error

### Пример 2
    Вход:
        1/0
    Выход:
        division by zero

### Пример 3
    Вход:
        2*2
    Выход:
        4

### Пример 4
    Вход:
        bad input
    Выход:
        syntax error

### Пример 5
    Вход:
        2.0*2.0
    Выход:
        syntax error

### Пример 6
    Вход:
        123()
    Выход:
        syntax error

### Пример 7
    Вход:
        1*2+3/4
    Выход:
        2

### Пример 8
    Вход:
        1*(2+3)/4
    Выход:
        1