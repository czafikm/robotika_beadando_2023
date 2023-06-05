# robotika_beadando_2023


## 1, Rendszer leírás

Webes felületen keresztül lehet egy LCD kijelzőre kirajzolni különböző formákat. 


## 2, Alkatrészek:

- potméter
- jumper kábelek
- gomb (5 darab)
- buzzer 
- LCD kijelző 


## 3, Használati esetek: 

- gomb lenyomásával fel
- gomb lenyomásával le
- gomb lenyomásával jobbra
- gomb lenyomásával balra
- gomb lenyomására a felület törlődik és a kurzor visszaáll a felület közepére
- potméter segítségével a rajzvonal vastagságának a beállítása
- felület elhagyás esetén buzzer megszólal

## 4, Képernyőtervek


![image](https://github.com/czafikm/robotika_beadando_2023/assets/114134902/ec70becd-38a9-4b21-bab3-123dec3cd259)



Sematikus rajz


![image](https://github.com/czafikm/robotika_beadando_2023/assets/114134902/b672b010-afbb-49ad-b4d3-3c2d61751196)


## 5, Állapotátmenet gráfok

### jelölések:
1, állapotok jelölése:
  - kurzor mozgása alapján:
  - S: Egy helyben áll
  - U: Fel mozog
  - D: Le mozog
  - R: Jobbra mozog
  - L: Balra mozog
  
2, gomblenyomások jelölése:
  - u: fel
  - d: le
  - r: jobbra
  - l: balra

### Kezdetben a kurzor középen helyezkedik el és onnan lehet különböző irányokba mozgatni. Azonban, ha a felület szélére ér és nem tud tovább menni abba az irányba, megszólal a buzzer ezt jelezve. Plusz a reset gombot megnyomva törlődik a felületet és visszaáll a kurzor a kezdőpontra.

![robotika_állapotátmenet](https://github.com/czafikm/robotika_beadando_2023/assets/114134902/16cb3ee1-38c8-40dc-ae60-2f2aa2265559)
