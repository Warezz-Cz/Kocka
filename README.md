Kocka project
===========================

Účel/Zadání/Funkce
-----------------------

Při stisku tlačítka se na LEDkách ukáže náhodné číslo 1 - 6
... jak když hážu kostkou.


Schéma zapojení
-----------------------

![schéma zapojení](./docs/schema.png)

Popis funkce
-----------------------

* Rozložení svítících/ zhasnutých LED bude v poli "cube"
* Náhodné číslo se generuje z času, po který uživatel drží tlačítko:
    - pokud uživatel drží tlačítkostále se inkrementuje promněnná num
    - pokud uživatel tlačítko pustí provedeme num % 6 tím získá 0 - 5 respektive 1 - 6
* zobrazím cube[num]
* V projetku je:
    1. jednoduchá varianta pokud jsou všechny LED na jednou portu
    2. Složitější, ale reálná varianta, kdy je každé LED na jiném portu

ToDo
-----------------------

Zhodnocení
-----------------------