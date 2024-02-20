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
