# Labs on "Programming in High Level Languages" (BSUIR, 3 term)

## Labs

* [Lab 1](https://github.com/moodtodie/sem3-labs/blob/main/Lab1-v6/main.cpp) ([Description](#Lab-1-variant-6));
* [Lab 2](https://github.com/moodtodie/sem3-labs/tree/main/Lab2-v1/) ([Description](#Lab-2-variant-1));
* [Lab 3](https://github.com/moodtodie/sem3-labs/tree/main/Lab3-v12/) ([Description](#Lab-3-variant-12));
* [Lab 4](https://github.com/moodtodie/sem3-labs/tree/main/Lab4-v12/main.cpp) ([Description](#Lab-4-variant-12));
* [Lab 5](https://github.com/moodtodie/sem3-labs/tree/main/Lab5-v12/main.cpp) ([Description](#Lab-5-variant-12));
* Lab 6 ([Description](#Lab-6-variant-6));
* Lab 7 ([Description](#Lab-7-variant-12));
* Lab 8 ([Description](#Lab-8-variant-3));
* Lab 9 ([Description](#Lab-9-variant-12));
* Lab 10 ([Description](#Lab-10-variant-12));
___________________________________________

### Lab 1 variant 6 [[Code]](https://github.com/moodtodie/sem3-labs/tree/main/Lab1-v6/main.cpp)

#### Цель работы:
Создание консольной программы включающей объекты и реализующей члены объектов c использованием спецификаторов доступа, конструкторы и деструктор, статические члены классо , особую инициализацию членов класса, дружественные функции и классы.

#### Задание
    Создать класс «Задание» со статистическими данными: id — приложение, name — название, result — процент выполнени. 
    Создать интегрированный класс «Проверяющий», который реализует метод установки процентов выполнение задания.

#### Общие требования к выполнению работы:
1. Создать проект консольной программы.
2. Создать базовый класс согласно заданию. Все данные класса описать в закрытой секции, все методы класса реализовать как открытые. Создать конструктор по умолчанию и конструктор инициализации. Создать деструктор.
3. Вне класса должна быть создана дружественная функция, предназначенная для вывода данных объекта на экран.
4. Для задания значений уникальных номеров использовать или статические члены класса или особую инициализацию членов класса.
5. Установка значений переменных должна иметь проверку на реальный диапазон значений.
6. В головной функции создать несколько одиночных экземпляров базового класса. Обработать все экземпляры базового класса с помощью заданного метода дружественного класса. Вывести содержимое переменных экземпляров классов на экран до и после этой обработки.
7. В головной функции создать массив экземпляров базового класса. Обработать все элементы массива с помощью заданного метода дружественного класса. Вывести содержимое переменных элементов массива на экран до и после этой обработки.

___________________________________________

### Lab 2 variant 1 [[Code]](https://github.com/moodtodie/sem3-labs/tree/main/Lab2-v1)

#### Цель работы:
Создание консольной программы реализующей перегрузку функции (в том числе с параметрами по умолчанию), перегрузку унарных и бинарных операторов, (в том числе и с помощью дружественных функций), реализацию функции преобразования типов.

#### Задание
    Целое число

#### Общие требования к выполнению работы:
1. Создать базовый класс согласно заданию. Все данные класса описать в закрытой секции, все методы класса
реализовать как открытые.
2. Создать конструктор инициализации с параметрами по умолчанию. Остальные конструкторы и деструктор
создать по необходимости.
3. Перегрузить операторы-члены класса:
 * присвоение =;
 * индексация элемента [];
 * инициализация ();
 * унарные арифметические (++);
 * бинарные арифметические (+ или ‑ ) и сравнения (> или < или ==), причем только для однотипных операндов;
4. Перегрузить дружественные функции-операторы:
 * унарные арифметические (--);
 * бинарные арифметические (+ или ‑ ) и сравнения (> или < или ==), причем для разных типов операндов;
 * вывода в поток (<<).
5. Создать функции преобразования:
 * во встроенный тип (int, double, …) (например, для подсчета характеристик массива (max, min, avg, count));
 * в пользовательский тип (например, класс описывающий размерность массива).
6. Провести вызовы перегруженных функций и операторов. Вывести результаты на экран.

___________________________________________

### Lab 3 variant 12 [[Code]](https://github.com/moodtodie/sem3-labs/tree/main/Lab3-v12)

#### Цель работы:
Создание консольной программы для реализации иерархии классов с использованием простого и множественного наследования, исследование спецификаций наследования, выполнение передачи параметров конструктору базового класса, разрешение с помощью виртуального наследования неоднозначностей при множественном наследовании.

#### Задание
    «Завод»

#### Общие требования к выполнению работы:
1. По полученному базовому классу создать классы наследников по двум разным ветвям наследования (B←P1←P11 и B←P2←P21):
 * во всех классах должны быть свои данные (характеристики объектов), расположенные в private или protected секциях;
 * во всех классах создать конструкторы инициализации объектов для всех классов (не забыть про передачу параметров в конструкции базовых классов);
 * во всех классах создать деструкторы;
 * во всех классах создать метод вывода объекта на экран (всех его параметров);
 * остальные методы создавать по необходимости.
2. Создать класс с множественным наследованием (P11 ← P3 → P21). Создать в этом классе выше описанные функции (в коде функций не использовать доступ к данным через оператор разрешения зоны видимости ::).
3. В головной функции создать экземпляр класса P3. Вывести содержимое экземпляра класса P3 на экран. Проверить, что получится, если не будет использовано виртуальное наследование.

___________________________________________

### Lab 4 variant 12 [[Code]](https://github.com/moodtodie/sem3-labs/tree/main/Lab4-v12/main.cpp)

#### Цель работы:
Создание консольной программы для реализации абстрактных классов и чисто виртуальных функций, создания и наследования виртуальных функций, изучения статического и динамического полиморфизма на основе виртуальных функций, включая виртуальные деструкторы.

#### Задание
    «Завод»

#### Общие требования к выполнению работы:
1. По полученному базовому классу создать классы наследников по двум разным ветвям наследования (B←P1←P11 и B←P2):
 * во всех классах должны быть свои данные (характеристики объектов), расположенные в private или protected секциях;
 * во всех классах создать конструкторы инициализации объектов для всех классов (не забыть про передачу параметров в конструкции базовых классов);
 * во всех классах создать деструкторы;
 * остальные методы создавать по необходимости.
2. Создать в базовом классе чисто виртуальные функции расчета (например, расчет площади фигуры и т.п.) и вывода объекта на экран (всех его параметров). Выполнить реализацию этих виртуальных функций в классах наследниках.
3. Задать в базовом классе деструктор как виртуальный.
4. В головной функции динамически создать массив указателей на базовый класс. Заполнить массив указателями на динамически создаваемые объекты производных классов (P1, P11, P2). Для каждого элемента массива проверить работу виртуальных функци . Удалить из памяти динамически выделенные объекты.

___________________________________________

### Lab 5 variant 12 [[Code]](https://github.com/moodtodie/sem3-labs/tree/main/Lab5-v12/main.cpp)

#### Цель работы:
Создание консольной программы для реализации шаблонов функций и классов, включая: явные специализации шаблонных функций и классов, стандартные типы в шаблонных классах.

#### Задание
    «Класс "Множество"»

#### Общие требования к выполнению работы:
1. Создать шаблонную функцию или класс согласно заданию.
2. Реализовать явную специализацию шаблонной функции или класса для строк символов (char *).
3. В шаблонных классах использовать стандартные типы и аргументы по умолчанию. Данные в шаблонных классах хранить в статическом массиве. Набор методов класса должен обеспечить основные операции с элементами объекта (добавление, удаление, поиск, просмотр, упорядочивание и т.п.) и операции над однотипными объектами (сравнение, сложение и т.п.).
4. Дополнительно рассмотреть реализацию наследования шаблонных классов (например, от простого базового класса).
5. В функции main выполнить действия с шаблонной функцией или классом, которые продемонстрируют работу методов.
6. Проверить использование специализаций, стандартных типов и аргументов по умолчанию.


___________________________________________

### Lab 6 variant 6

#### Цель работы:
Создание консольной программы для реализации обработки ошибок с использованием механизма обработки исключительных ситуаций, создание специальных классов обработки исключительных ситуаций, рассмотрение замены обработчиков функций terminate() и unexpected() собственными функциями.

#### Задание
    «Класс "Множество"»

#### Общие требования к выполнению работы:
1. Создать обычный или шаблонный класс согласно заданию. Данные в классе хранить в статическом массиве. Набор методов класса должен обеспечить основные операции с элементами объекта (добавление, удаление, поиск, просмотр и т.п.) и операции над однотипными объектами (сравнение, присвоение и т.п.).
2. Обработку всех ошибочных ситуаций реализовать с использованием схемы обработки исключительных ситуаций. Реализовать собственный класс обработки исключительной ситуации.
3. Рассмотреть замену обработчиков функций terminate() и unexpected() собственными функциями.
4. В функции main выполнить действия с экземпляром класса, которые продемонстрируют работу методов, в том числе и реакцию на возникновение ошибок.
5. Проверить работу обработки исключительных ситуаций.

___________________________________________

### Lab 7 variant 12

#### Цель работы:
Создание консольной программы для реализации работы с данными, которые хранятся в текстовых и бинарных файлах с использованием: перегрузки операторов ввода-вывода, управления курсорами чтения и записи, с обработкой ошибок состояния потока ввода-вывода, а также вывод данных на консоль с использованием возможностей управления форматом флагами и манипуляторами, создание манипуляторов.

#### Задание
    «Растение»

#### Общие требования к выполнению работы:
1. Создать класс, согласно заданию, который будет описывать некоторый объект (задать не менее трех характеристик) и базовые методы для работы с ним.
2. Создать в этом классе операторы работы с потоками ввода-вывода, ориентированными на работу с текстовыми файлами.
3. Создать в этом классе методы (чтение, запись, …) для работы с текстовыми файлами в бинарном режиме (на основе методов потока для работы с отдельными символами).
4. Создать в этом классе методы (чтение, запись, …) для работы с бинарными файлами в бинарном режиме (на основе методов потока для работы с блоками памяти).
5. Для обработки всех ошибочных ситуаций использовать конструкцию try…catch().
6. В головной функции выполнить обработку данных в трех режимах:
 * работа с текстовым файлом в текстовом режиме;
 * работа с текстовым файлом в бинарном режиме;
 * работа с бинарным файлом в бинарном режиме;
   Для каждого выше указанного варианта выполнить следующие действия:
 * сформировать файл данных (не менее 5 строк или записей);
 * вывести записи данных в прямом и обратном порядке не считывая все записи в память (при вводе-выводе данных применить знания флагов вывода и манипуляторов);
 * найти записи по условию (по шаблону названия) и вывести их на экран;
 * удалить записи по условию в файле, удаляемые записи вывести на экран.
7. Проверить обработку исключительных ситуаций.

___________________________________________

### Lab 8 variant 3

#### Цель работы:
Создание консольной программы с реализацией объектов для хранения данных в динамической памяти на основе шаблонных классов, изучение указателей на объекты.

#### Задание
    «Список односвязный»

#### Общие требования к выполнению работы:
1. Построить шаблонный класс, который будет описывать элемент хранимых данных, доступ к ним, сравнение элементов и т.п. по необходимости.
2. Для полученного варианта задания, построить контейнерный шаблонный класс операций над элементами данных, включающий операции:
 * добавления;
 * удаления;
 * поиска;
 * просмотра;
 * остальные функции добавлять по необходимости.
3. Для данного контейнерного класса предусмотреть при формировании элемента задание режима уникальных элементов (т.е. проверку на дублирование значений элементов).
4. Для обработки всех ошибочных ситуаций использовать конструкцию try…catch().
5. Дополнительно к контейнеру рекомендуется реализовать класс-итератор.
6. В функции main создать три экземпляра шаблонного класса-контейнера для разных типов данных. Работа с этими объектами должна демонстрироваться на следующих операциях: добавить – просмотреть – найти – удалить – найти – просмотреть.
7. Проверить обработку исключительных ситуаций (например, чтение из пустого стека, дублирование объектов и т.п.).

___________________________________________

### Lab 9 variant 12

#### Цель работы:
Создание консольной программы с реализацией объектов, которые находятся в собственном пространстве имен, реализация взаимодействия классов путем наследования, композиции и агрегации, рассмотрение особенностей построения диаграммы классов.

#### Задание
    «Архитектурный_объект, координата, автор, материал, описание, памятник»

#### Общие требования к выполнению работы:
1. Для полученного списка классов требуется сформировать диаграмму классов, используя принципы наследования, композиции и агрегации.
2. Создать собственное пространство имен, в которое будут помещены все создаваемые пользовательские классы.
3. Реализовать классы, согласно диаграмме классов, причем:
 * во всех классах должны быть свои данные в виде 1-2 переменных, представляющие характеристики объектов и расположенные в private или protected секциях;
 * во всех классах создать конструктор по умолчанию и конструктор инициализации (не забыть про передачу параметров в конструкции базовых классов);
 * во всех классах создать деструктор;
 * во всех классах создать метод просмотра содержимого;
 * остальные методы создавать по необходимости.
4. Описание каждого класса требуется реализовать в отдельной паре файлов (.h и .cpp).
5. В головной функции создать объект класса, расположенного последним в списке, выполнить доступ к его методам и методам его составных частей.
6. Рассмотреть вызовы конструкторов и деструкторов при создании и разрушении объектов. Рассмотреть различные виды организации доступа к элементам собственного пространства имен и пространства имен std.

___________________________________________

### Lab 10 variant 12

#### Цель работы:
Создание консольной программы для представления данных с использованием контейнеров и обработки их с использованием алгоритмов и функторов библиотеки STL.

#### Задание
    «Обработка файлов инициализации параметров»

#### Общие требования к выполнению работы:
1. Реализовать программу, которая обрабатывает строки текстового файла согласно заданию, а результаты обработки помещает в строки другого текстового файла. Для хранения и обработки данных использовать контейнеры и алгоритмы библиотеки STL.
2. На экран выводить отладочную информацию: какой файл открыт (или ошибка открытия файла), номер обработанной строки и результат ее обработки и т.п. Для обработки всех исключительных ситуаций использовать конструкцию try…catch().
