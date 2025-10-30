# Semestrální práce Hadi

#### Autor: Milan Jiříček a Kryštof Buben

Tato semestrální práce je vytvořena v rámci předmětu Architektura počítačů na ČVUT FEL.
Cílem hry je nasbírat, co největší skóre. Hra končí, pokud had narazí do zdi nebo do sebe sama.

## Manual

### Instalace
K instalaci je potřeba deska MZAPO. Tento program je potřeba zkompilovat a nahrát do desky.
V repu se nachází Makefile, který je nastavený pro kompilaci na desce MZAPO. Pro upload programu do desky je potřeba
změnit ```TARGET_IP ?= 192.168.223.xxx```, kde za xxx dosadíte IP adresu desky.
Poté pomocí ```make all``` můžete zkompilovat a slinkovat program. Pro upload do desky a spuštění aplikace použijte ```make run```.

### Ovládání

#### Menu

Tato hra se ovládá pomocí točících knoflíků na desce. Celé prostředí menu se ovládá **červeným knoflíkem**.
Točením vybírá hráč volbu a stiskem tlačítka potvrdí volbu.  
Menu se skládá ze tří částí:

- **PLAY**
  - Lze vybrat jaký herní mód che hráč hrát
  - Po vybrání se spustí hra
  - Vybrat je možné z následujících herních módů:
    - **Single**
      - Hraje pouze jeden hráč
    - **Multi**
      - Hraje se proti jinému hráči
    - **AI**
      - Hraje se proti počítači
- **MAP**
  - Lze vybrat jakou mapu chce hráč hrát
  - Po vybrání mapy se hráč vrátí do menu
  - Mapa se uloží do nastavení a při dalším spuštění hry se načte
- **DIFFICULTY**
  - Hráč si vybere obtížnost hry
  - Vyšší obtížnost zvyšuje rychlost hadů
  - Obtížnost se uloží do nastavení a při dalším spuštění hry se načte

#### Hra

Hra se ovládá pomocí **točících knoflíků**. Ovládání je stejné pro všechny herní módy.  
Tzn. hráč ovládá hada pomocí **červeného** knoflíku. Pokud hraje hráč proti jinému hráči, tak druhý hráč ovládá hada
pomocí **modrého** knoflíku.
Pokud hraje hráč proti počítači, tak počítač ovládá hada sám.  
Hra se ovládá tak, že točením knoflíku se had otáčí do daného směru.  
Hra se ukončí stiskem **červeného** tlačítka.

#### Konec hry

Konec hry nastane pokud se had sám do sebe zakousne nebo pokud se zakousne do okraje mapy.
Po skončení hry se zobrazí skóre. Hráč se může vrátit do menu stiskem **červeného** tlačítka.
Pokud hráč chce hrát znova se stejným nastavením, tak stiskne **modré** tlačítko.

## Wiki
Pro pokračování dokumentace naštivte wiki stránku na gitlabu.


# Semestrální práce Hadi

#### Autor: Milan Jiříček a Kryštof Buben

Tato semestrální práce je vytvořena v rámci předmětu Architektura počítačů na ČVUT FEL. Cílem hry je nasbírat, co největší skóre. Hra končí, pokud had narazí do zdi nebo do sebe sama.

## Manual

### Instalace

K instalaci je potřeba deska MZAPO. Tento program je potřeba zkompilovat a nahrát do desky. V repu se nachází Makefile, který je nastavený pro kompilaci na desce MZAPO. Pro upload programu do desky je potřeba změnit `TARGET_IP ?= 192.168.223.xxx`, kde za xxx dosadíte IP adresu desky. Poté pomocí `make all` můžete zkompilovat a slinkovat program. Pro upload do desky a spuštění aplikace použijte `make run`.

### Ovládání

#### Menu

Tato hra se ovládá pomocí točících knoflíků na desce. Celé prostředí menu se ovládá **červeným knoflíkem**. Točením vybírá hráč volbu a stiskem tlačítka potvrdí volbu.\
Menu se skládá ze tří částí:

- **PLAY**
  - Lze vybrat jaký herní mód che hráč hrát
  - Po vybrání se spustí hra
  - Vybrat je možné z následujících herních módů:
    - **Single**
      - Hraje pouze jeden hráč
    - **Multi**
      - Hraje se proti jinému hráči
    - **AI**
      - Hraje se proti počítači
- **MAP**
  - Lze vybrat jakou mapu chce hráč hrát
  - Po vybrání mapy se hráč vrátí do menu
  - Mapa se uloží do nastavení a při dalším spuštění hry se načte
- **DIFFICULTY**
  - Hráč si vybere obtížnost hry
  - Vyšší obtížnost zvyšuje rychlost hadů
  - Obtížnost se uloží do nastavení a při dalším spuštění hry se načte

#### Hra

Hra se ovládá pomocí **točících knoflíků**. Ovládání je stejné pro všechny herní módy.\
Tzn. hráč ovládá hada pomocí **červeného** knoflíku. Pokud hraje hráč proti jinému hráči, tak druhý hráč ovládá hada pomocí **modrého** knoflíku. Pokud hraje hráč proti počítači, tak počítač ovládá hada sám.\
Hra se ovládá tak, že točením knoflíku se had otáčí do daného směru.\
Hra se ukončí stiskem **červeného** tlačítka.

#### Konec hry

Konec hry nastane pokud se had sám do sebe zakousne nebo pokud se zakousne do okraje mapy. Po skončení hry se zobrazí skóre. Hráč se může vrátit do menu stiskem **červeného** tlačítka. Pokud hráč chce hrát znova se stejným nastavením, tak stiskne **modré** tlačítko.

## Architektura aplikace

Program je napsaný v jazyce C. Základ programu je rozdělen do několika modulů.

![diagram](uploads/diagram.png)

### Start_semestralka

Jádro programu. Zde se nachází funkce main, která spouští celý program. Zde se také nachází funkce `init()`, která inicializuje periferie. V `main()` se nachází switch, který rozhoduje mezi složkami v menu.

### window_module

Tento modul se stará o vykreslování celých oken. Po spuštění programu právě _start_semestralka_ odkáže na funkci

```c
/* main function of main menu */
int main_menu_control(uint32_t *knobs) {
    int active_menu_item = 0;
    *knobs = update_knobs();
    knob_bounce(knobs);
    while (knob_press(knobs, RED_KNOB)) {
        *knobs = update_knobs();
        active_menu_item = ((*knobs >> 16) & 0xff >> 4) / GAMEMODES_COUNT; // dodelat konstatu
        show_main_menu(active_menu_item);
    }
    return active_menu_item;
}
```

Tato funkce se stará o vykreslení menu a o jeho ovládání pomocí točících knoflíků. Funkce `show_main_menu()` vykreslí menu graficky na obrazovku. Anagolicky funguje i vykreslování všech pod menu.

### settings

Modul se stará o vytvoření struktury:

```c
struct settings {
    short int gamemode;
    short int difficulty;
    short int map;
};
```

Tato struktura slouží k uchování nastavení a další moduly podle ní generují hru.

### game_selector

Modul game_selector se přímo stará o samotnou hru. Po výběru v herního režimu v menu se zavolá funkce `void setup_game(uint32_t *knobs, struct settings *settings)`, která zparsuje výběr módu a vybere správnou funkci.\
V jádru všechny herní módy stojí na funkci:

```c
/* core function of game running */
int game_run(uint32_t *knobs, struct settings *settings, struct player **players, size_t size, int ai) {
    // set speed of the game
    struct timespec loop_delay = {.tv_sec = 0, .tv_nsec = get_delay(settings) * SECOND};
    // draw snake and score for each player
    draw_players(players, size);
    knob_bounce(knobs); // wait for knob to be released
    unsigned short int end = 0; // flag for end of game
    while (knob_press(knobs, RED_KNOB)) {
        *knobs = update_knobs();
        // checks if any player changed direction
        check_directions(players, size, *knobs, ai);
        end = check_snakes(players, size);
        if (end > 0) { // if game ended
            break;
        }
        draw_players(players, size);
        display_refresh();
        clock_nanosleep(CLOCK_MONOTONIC, 0, &loop_delay, NULL); // sleep for delay
        setLEDtoColor(NO_LED_COLOR); // turn off all leds
    }
    return end_game(knobs, players, size, end); // end game window
}
```

Je to srdce celé hry. Nejprve se nastaví rychlost hry, kterou si uživatel zvolil v již zmíněném nastavení. Poté nastane loop, který je ukončen stiskem červeného tlačítka, nebo pokud se nějaký had zakousne. Do té doby se neustále vykresluje had a skóre, a každý tik se hadi posouvají podle nastavené _direction_, která se odvíjí od točících knoflíků.

### player

Modul player se stará o vytvoření struktury:

```c
struct player {
    struct snake_t *snake;
    long int score;
    int knob_offset;
    unsigned int prev_knob;
};
```

Tato struktura slouží k uchování informací o hráči. Obsahuje ukazatel na hada, skóre, offset knoflíku a předchozí hodnotu knoflíku. `int knob_offset` je hodnota, která bitově posune registr knoflíků aby dostal správnou hodnotu knoflíku. `unsigned int prev_knob` udržuje poslední stav knoflíku, aby program mohl rozpoznat změnu směru hada.\
Dále se modul stará i o přidávání score a kontroly hada. Například funkce `void check_direction(struct player *player, const unsigned int knobs)` kontroluje změnu směru hada. Nicméně knoflík má hodnotu 0-255, takže nastal problém, pokud uživatel otočil tlačítkem od 255 na 0, nebo naopak. V tomto případě by došlo k opačnému otočení hada. Proto je zde implementována odchylka, která se při překročení ještě toleruje. Bere se vždy rozdíl alespoň o 4 "body".\
Player se také stará o hlídání kolize hada sám se sebou, s okrajem mapy nebo snědením jídla. Modul také kontroluje v multiplayeru kolize hlav hadů. Toto se kontroluje zvlášť protože, hadi pouze sledují pole před sebou, a pokud jsou hlavy dvou hadů vedle sebe, tak pole viděly jako prázdné a prolínali se.

### snake

Modul snake řeší problém uchovávání souřadnic hada a jeho délky. Původně bylo zamýšleno pole, ale to bylo velmi neefektivní, protože se muselo přesouvat celé pole. Proto nakonec bylo zvoleno řešení pomocí dvousměrného spojového seznamu.

```c
struct snake_t {
    unsigned short int color;
    size_t size;
    int direction;
    struct body_part_t *head;
    struct body_part_t *tail;
};
```

Struktura obsahuje barvu hada, jeho délku, směr, ukazatel na hlavu a ocas.

```c
struct body_part_t {
    struct body_part_t *next;
    struct body_part_t *previous;
    unsigned int x;
    unsigned int y;
};
```

Struktura obsahuje ukazatel na předchozí a následující část hada, a souřadnice. Modul přidává část těla k hlavě a odebírá ocas. Pro pohyb, který kombinuje tyto dvě akce slouží funkce `int move_snake(struct snake_t *snake, unsigned int x, unsigned int y)`.

### food

Modul food se stará o vytvoření jídla a jeho umístění na mapě. Generovat náhodné souřadnice a kontrolovat, zda je pole volné, je neefektivní hlavně ke konci hry, kdy je málo volných polí. Proto bylo zvoleno řešení, kdy je neprve vytvořeno pole všech volných polí, a následně se vybere náhodné pole z tohoto pole.

### path_finding

Pro herní mód hraní proti AI bylo nutné zvolit nějakou metodu jak se AI bude pohybovat. Nejprve byl zvolen Dijikstra algoritmus, ale ten byl velmi neefektivní, protože se by se muselo počítat při každém pohybu hada znovu. Zvolen byl algoritmus, který spočítá Euklidovskou vzdálenost mezi hlavou hada a jídlem, a následně se pohne směrem, který je nejblíže jídlu. Tento algoritmus je implementován v modulu path_finding a velice se osvědčil.

### draw_module

Tento modul obsahuje větší funkce, které kombinují několik menších funkcí z modulu draw_tools. Například se zde nachází funkce, která vykresluje části hada na správné pozice ve hře a se správnou orientací hlavy a ocasu. Vykresluje celou herní plochu podle toho, kde se nachází překážky či jídlo, nebo také aktuální skóre hráčů na spodní část obrazovky. Po skončení hry vykreslí závěrečné menu.

### draw_tools

Zde se nachází větší množství funkcí užitečných pro grafiku. Například pro práci s barvama se ze nachází funkce na ztmavení barvy nebo na převod z u16 do RGB standartu. Další drobné funkce jsou například vykreslení čtverce, jednoho i více pixelů nebo znaku.

Pro vypisování textu byla použita funkce draw_char z jednoho z ukázkových kódů na cvičeních. Na tu byla navázána funkce draw_string, která vykreslí řetězec textu s možností pozadí textu.

Vykreslování jednotlivých grafik zajišťují funkce draw_graphics a draw_sign, které dokáží zpracovat dvojrozměrná pole a na základě hodnot v tomto poli vykreslit cokoliv.

### graphics & signs

Tyto dva moduly obsahují několik dvojrozměrných polí, které reprezentují různé obrázky pixel po pixelu. Každá hodnota v poli reprezentuje barvu na určité pozici. Některé byly dělány ručně, některé převedeny jednoduchým kódem z ASCII art přímo do formy dvojrozměrného pole.

```c
int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    char input;
    printf("{");
    while((input = fgetc(file)) != EOF) {
        if (input == '\n') {
            printf("},\n{");
        } else if (input == ' ') {
            printf("0,");
        } else if (input == ':') {
            printf("1,");
        } else {
            printf("2,");
        }
    }
    printf("}");
    return 0;
}
```

Tento kód byl použit na převod vygenerovaného ASCII art přímo na pole. Příklad vygenerovaného slova SNAKE na webu [`zde`](https://patorjk.com/software/taag/#p=display&h=0&v=0&f=Doh&t=SNAKE).

## Závěr

Závěrem bychom chtěli poděkovat panu RNDr. Petr Štěpánovi, Ph.D. za pomoc při tvorbě tohoto projektu. Projekt byl velmi zajímavý a poučný, a doufáme, že se vám bude líbit.
