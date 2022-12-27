#include <iostream>
#include <limits>
/* limits behövdes för att kunna rensa hela cin-buffern
   (=om användaren ej matat in siffror, vilket jag ville kunna hantera) */

using namespace std;

int main() {
  // till David H: Jag har valt att använda din uppdelning
  // i numrerade delblock som skelett för uppgiften
  // --
  // Jag har använt Vim som texteditor för redigeringen
  // och använt två blanksteg för indrag - inga tabs
  // (':set shiftwidth=2')

  // - 1. Programmet öppnar med ett
  //   välkomstmeddelande och informerar
  //   om att det ska beräkna växel för
  //   en/flera varor som användare
  //   köper och betalar för.
  cout << "Välkommen till PengarTillbaka!\n";
  cout << "(Programmet beräknar din växel tillbaka vid köp av en/flera varor.)\n";
  cout << endl;

  cout << "--- Startar inmatning ---\n";
  // - 2. Deklarera de variabler som
  //   behövs för att räkna växel.
  float price_item = 0;
  float sum_goods = 0;
  float payment_total = 0;
  // --
  float total_change = 0;
  int change_intpart = 0;
  float change_fractpart = 0;
  // --
  int current_unit = 0;  // Nuvarande sedel/mynt-enhet vid uppräkning av växel tillbaks
  int nums_per_unit = 0;

  // - 3. Be användaren att mata in
  //   varans pris och läs in det värdet
  while (cin) {
    cout << "Mata in värde på en vara: ['B' = betala / 'A' = avsluta] \n";
    cin >> price_item;

    if (price_item < 0)
    {
      cout << " --- (Inga negativa värden. Försök igen.)\n";
      continue;
    }
    else if (!cin)  // 'om inmatning ej stämmer med variabelns typvärde'
                    // (=om användaren matat in t.ex. bokstäver)
                    // Not: (provade först med (!isdigit(price_item))) 
    {
      cin.clear();
      char cin_buffer;
      cin >> cin_buffer;

      // Undantag för 'B/b' (Betala) och 'A/a' (Avsluta programmet)
      if (cin_buffer == 'B' || cin_buffer == 'b')
      {
        break;
      }
      else if (cin_buffer == 'A' || cin_buffer == 'a')
      {
        return 0;
      }

      // Rensa cin-buffern inför nästa varv/körning
      // (=försökte först med bara cin.ignore()
      //  men behövde nedanstående för att rensa hela buffern)
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout << " --- (Bara siffror. Försök igen.)\n";
      continue;
    }

    sum_goods += price_item;
    cout << "-- Din summa är nu " << sum_goods << "\n";
  }
  cout << endl;


  cout << "--- Nu är vi i kassan/hopräkning ---\n";
  // - 4. Be användaren att mata in
  //   betalade pengar
  cout << "Total summa för varor: " << sum_goods << endl;

  while (cin) {
    cout << "Ange summa att betala med: ";
    cin >> payment_total;

    // Kontroller av inmatade värden enligt punkt 5 nedan
    if (!cin)
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout << " --- (Bara siffror. Försök igen.)\n";
      continue;
    }
    else if (payment_total == sum_goods)
    {
      cout << "Allt klart: Ingen växel tillbaks \n";
      return 0;
    }
    else if (price_item < 0)
    {
      cout << " --- (Inga negativa värden. Försök igen.)\n";
      continue;
    }
    else if (payment_total < sum_goods)
    {
      cout << " --- (För låg summa. Försök igen.)\n";
      continue;
    }

    break;
  }


  // - 5. Med en enkel resta räkna ut
  //   växeln tillbaka
  //   Glöm inte att först kontrollera
  //   de inmatade värdena.
  cout << "(beräknar växel...)" << endl;
  total_change = payment_total - sum_goods;
  cout << total_change << endl;

  // Separera kronor och ören
  change_fractpart = total_change - (int)total_change;
  change_intpart = (int)total_change;

  // och avrunda till jämna 50-öringar
  if (change_fractpart < 0.25) {
    change_fractpart = 0;
  }
  else if (change_fractpart >= 0.25 && change_fractpart <= 0.75) {
    // not: enligt uppgiftsbeskrivning = 76 och uppåt avrundas uppåt
    // snarare än 75 och uppåt
    change_fractpart = 0.5;
  }
  else if (change_fractpart > 0.75) {
    // Avrunda kronor uppåt genom att öka med ett
    change_intpart++;
    change_fractpart = 0;
  }


  cout << endl;
  // Skriv ut värdet på växel, inklusive ören
  cout << "Växel tillbaks blir: " << change_intpart + change_fractpart << " kr" << endl;

  // - 6. Kalkylera hur många sedlar och
  //   mynt som användare ska få. 
  //   Använd division och modulus för
  //   detta.
  cout << "---- Uppräkning av växeln i kr:\n";

  cout << "sedlar----\n";
  // 1000-sedlar tillbaks
  current_unit = 1000;
  nums_per_unit = change_intpart / current_unit;
  change_intpart %= current_unit;
  // --
  cout << current_unit << ": " << nums_per_unit << " st" << endl;

  // 500-sedlar tillbaks
  current_unit = 500;
  nums_per_unit = change_intpart / current_unit;
  change_intpart %= current_unit;
  // --
  cout << current_unit << ": " << nums_per_unit << " st" << endl;

  // 100-sedlar tillbaks
  current_unit = 100;
  nums_per_unit = change_intpart / current_unit;
  change_intpart %= current_unit;
  // --
  cout << current_unit << ": " << nums_per_unit << " st" << endl;

  // 50-sedlar tillbaks
  current_unit = 50;
  nums_per_unit = change_intpart / current_unit;
  change_intpart %= current_unit;
  // --
  cout << current_unit << ": " << nums_per_unit << " st" << endl;

  // 20-sedlar tillbaks
  current_unit = 20;
  nums_per_unit = change_intpart / current_unit;
  change_intpart %= current_unit;
  // --
  cout << current_unit << ": " << nums_per_unit << " st" << endl;

  cout << "mynt----\n";
  // 10-mynt tillbaks
  current_unit = 10;
  nums_per_unit = change_intpart / current_unit;
  change_intpart %= current_unit;
  // --
  cout << current_unit << ": " << nums_per_unit << " st" << endl;

  // 5-mynt tillbaks
  current_unit = 5;
  nums_per_unit = change_intpart / current_unit;
  change_intpart %= current_unit;
  // --
  cout << current_unit << ": " << nums_per_unit << " st" << endl;

  // 1-mynt tillbaks
  current_unit = 1;
  nums_per_unit = change_intpart / current_unit;
  change_intpart %= current_unit;
  // --
  cout << current_unit << ": " << nums_per_unit << " st" << endl;


  // Not/Fråga: Jag valde att ta med 50-öringar också
  // eftersom det nämndes i beskrivningen av växel-beräkningen
  cout << "(och " << change_fractpart * 100 << " öre)" << endl;

  return 0;
}
