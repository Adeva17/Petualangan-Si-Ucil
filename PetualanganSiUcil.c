#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define MAX_HP 3

int musuhke = 0;

typedef struct{
    char nama[100];
    int hp;
    int action;
}Musuh;

typedef struct{
    int hp;
    int action;
}Player;

Player ucil;

Musuh musuh[2];

/*
    ======================KUMPULAN FUNGSI INISIASI======================
*/

void init_ucil(){
    ucil.hp = MAX_HP;
}

void init_musuh(int keberapa){
    if(keberapa == 0){
        strcpy(musuh[0].nama, "Goblin");
        musuh[0].hp = MAX_HP;
    }
    else {
        strcpy(musuh[1].nama, "Dora");
        musuh[1].hp = MAX_HP;
    }
}

/*
    ======================AKHIR KUMPULAN FUNGSI INISIALISASI======================
*/

/*
    ======================KUMPULAN FUNGSI DISPLAY======================
*/

// fungsi untuk memposisikan letak output
void gotoxy(int x, int y)
{
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// fungsi ini berguna untuk menampilkan tampilan teks berkedip di tengah layar (digunakan sebagai pembatas antar bagian game).
void tampilanbesar(char teks[]) {
    system("cls");
    int teks_length = strlen(teks);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int max_x = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int max_y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    int teks_x = (max_x-teks_length) / 2;
    int teks_y = max_y / 2;

    char tekan[] = "Tekan tombol apa saja";
    int tekan_length = strlen(tekan);
    int tekan_x = (max_x - tekan_length) / 2;
    int tekan_y = teks_y+2;

    while (!_kbhit())
    {
        gotoxy(teks_x, teks_y);
        printf("%s", teks);
        gotoxy(tekan_x, tekan_y);
        printf("%s", tekan);

        Sleep(400);
        system("cls");
        
        gotoxy(tekan_x, tekan_y);
        printf("%s", tekan);
        Sleep(400);
    }
    _getch();
}

// fungsi typewriting digunakan untuk mengoutput teks huruf demi huruf. Memberikan efek ketik
void typewriting(char teks[]){
    
    int ukuran = strlen(teks);
    for(int i = 0; i<ukuran; i++){
        printf("%c", teks[i]);
        Sleep(25);
    }
    printf("\n\n");
    Sleep(1000);
    
}

void startingscreen(){
    tampilanbesar("P E T U A L A N G A N   S I   U C I L");
}

void gameover(){
    tampilanbesar("G A M E   O V E R");
}

void theend(){
    tampilanbesar("T H E   E N D");
}

// fungsi ini menampilkan status dari Ucil dan juga musuh berupa nama dan juga HP yang tersisa
void displaystatus(){
    system("cls");
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int max_x = csbi.srWindow.Right;
    int min_x = csbi.srWindow.Left;
    int max_y = csbi.srWindow.Top;
    int min_y = csbi.srWindow.Bottom;

    int nama_length = strlen(musuh[musuhke].nama);
    int namamusuh_length = max_x - nama_length;

    gotoxy(namamusuh_length, max_y);
    printf("%s\n", musuh[musuhke].nama);
    gotoxy(namamusuh_length, max_y + 1);
    printf("%d/3", musuh[musuhke].hp);

    gotoxy(min_x, max_y);
    printf("Ucil\n");
    gotoxy(min_x, max_y + 1);
    printf("%d/3", ucil.hp);

    gotoxy(min_x, min_y-3);
    printf("1. Melee\n2. Ranged\n3. Defend");
}

/*
    ======================AKHIR KUMPULAN FUNGSI DISPLAY======================
*/

/*
    ======================KUMPULAN FUNGSI STORY======================
*/

// fungsi ini menampilkan prologue
void prologue(){
    system("cls");
    typewriting("Pada suatu hari... seorang anak bernama Ucil sedang iseng mengejar soang UPN...");
    typewriting("Soang tersebut teriak! Ketakutan dikejar si Ucil...");
    typewriting("Ucil hanya tertawa sambil mengejar soang tersebut... Sampai ia tidak sadar ia terjegal\nsebuah batu besar dan terjatuh ke dalam danau UPN...");
    typewriting("Ucil\t: \"AGHHHHH!!!!\"");
    typewriting("Air dingin menyelimuti tubuhnya...");
    typewriting("Ia kaget dan tidak bisa bernafas...");
    typewriting("Ia berusaha naik ke permukaan, tetapi ia tidak tahu arah mana yang benar...");
    typewriting("Kesadarannya mulai hilang...");
    typewriting("...");
    typewriting("...");
    typewriting("...");

    printf("*Tekan enter...*");
    _getch();
    system("cls");

    typewriting("...");
    typewriting("...");
    typewriting("Ucil\t: \"Maafkan aku mama.. Aku tidak seharusnya berkeliaran sendirian seperti tadi...\"");
    typewriting("...");
    typewriting("Ucil\t: \"Andaikan aku dapat membenahi semua yang aku perbuat...\"");
    typewriting("...");
    typewriting("???\t: \"M. A. K. A. . B. E. N. A. H. I. L. A. H.\"");
    typewriting("!!!!!!!!!!!!!!!!!!!!!!!");
    Sleep(1000);

    printf("*Tekan enter...*");
    _getch();
    system("cls");

    typewriting("Ucil\t: \"WAH!\"");
    typewriting("Ucil terbangun di pesisir pantai... Semuanya terasa berbeda...");
    typewriting("Pasir menjadi dingin, tetapi cuaca begitu hangat...");
    typewriting("Ucil\t: \"!!\"");
    typewriting("Ucil\t: \"Ada sebuah pedang, panah, dan perisai disini... Kok bisa?\"");
    typewriting("Ucil\t: \"Sebaiknya aku bawa saja untuk jaga-jaga...\"");
    printf("*Mendapatkan pedang!!\n");
    _getch();
    printf("*Mendapatkan panah!!\n");
    _getch();
    printf("*Mendapatkan perisai!!\n");
    _getch();

    printf("*Tekan enter...*");
    _getch();
    system("cls");
    
}

// fungsi ini menampilkan story ketika Ucil mengencounter Goblin
void goblinencounter(){
    system("cls");
    typewriting("Ucil pun berkelana... berusaha mencari untuk apa dia berada disini...");
    typewriting("Sampai tiba-tiba...");
    system("cls");
    typewriting("???\t: \"NGAPAIN LU DISINI!?\"");
    typewriting("Ucil\t: \"ASTAGHFIRULLAH!! Kamu sangat mengagetiku! Kenapa kamu berwarna hijau?\"");
    typewriting("Goblin\t: \"Namaku adalah Goblin. Aku tidak pernah melihat dirimu disini. Kamu pasti ingin merusak kampungku!\nsantai saja bocah, aku akan mengalahkanmu begitu cepat sehingga kamu bahkan tidak punya waktu untuk berkedip.\"");
    typewriting("Goblin\t: \"HIYYYAAAHHH!\"");
}

// fungsi ini menampilkan story ketika Ucil mengencounter Dora
void doraencounter(){
    system("cls");
    typewriting("Goblin\t: \"UGH!!\"");
    typewriting("Goblin\t: \"Bagaimana bisa bocah sepertimu mengalahkan diriku! Kamu pasti anak dari penyihir!!\"");
    typewriting("Ucap sang Goblin, kesakitan.");
    typewriting("Ucil\t: \"Tidak! Aku saja tidak tahu mengapa aku disini. Aku tenggelam di danau UPN. Lalu tiba-tiba aku berada disini.\"");
    typewriting("Goblin\t:\"D-danau UPN!? Apakah mungkin...?\"");
    typewriting("Ucil\t:\"???\"");
    
    printf("*Tekan enter...*\n");
    _getch();
    system("cls");

    typewriting("Goblin ketakutan. Ia mengingat cerita kuno yang selalu dibicarakan oleh penduduk kampung...");
    typewriting("Goblin\t: \"T-tidak. Tidak mungkin! Kamu hanyalah bocah aneh.\"");
    typewriting("Goblin\t: \"Lebih baik kamu pergi ke arah selatan!. Kampungku adalah jalan buntu yang tidak memiliki apapun.\"");
    typewriting("Goblin\t: \"Temuilah seseorang perempuan kecil disana. Mungkin dia bisa membantumu.\"");

    printf("*Tekan enter...*\n");
    _getch();
    system("cls");

    typewriting("Ucil\t: Baiklah.. aku akan memercayaimu, Goblin. Maafkan aku jika aku menyakitimu.\"");
    typewriting("Goblin\t: \"Huh! Seranganmu bahkan tidak meninggalkan luka padak- UHUK!!.\"");
    typewriting("Goblin\t: *Sialan*");
    typewriting("Ucil hanya melihat Goblin dengan raut muka kebingungan.");
    typewriting("Goblin\t: \"Apa yang kau lakukan!? Sana pergi ke selatan. Jangan pernah kembali ke sini!\"");
    typewriting("Ucil\t: \"B-BAIK! Maaf pak Goblin!\"");
    typewriting("Ucil segera bergegas menuju ke arah selatan. Mengikuti panduan yang diberikan oleh Goblin.");

    printf("*Tekan enter...*\n");
    _getch();
    system("cls");

    typewriting("...");
    typewriting("...");
    typewriting("...");
    typewriting("Ucil\t: \"D-dingin s-sekali...\"");
    typewriting("...");
    typewriting("Salju mulai turun...");
    typewriting("Ucil terus berjalan ke arah selatan... Menuju ke arah yang tidak pasti... Hanya bermodalkan kepercayaan kepada Goblin");
    typewriting("Senyap...");
    typewriting("...");
    typewriting("...");
    typewriting("...");
    typewriting("*BRUKK!!");
    typewriting("Ucil menabrak sesuatu...");

    printf("*Tekan enter...*\n");
    _getch();
    system("cls");

    typewriting("Ucil\t: \"HEY! Siapa...?\"");
    typewriting("???\t: \"Hehehehe\"");
    typewriting("Dora\t: \"Aku Dora! Senang bertemu denganmu!!\"");
    typewriting("Dora sangatlah kecil. Ia tampak sangat lucu. Bagaikan anak kecil yang kehilangan orangtuanya.");
    typewriting("Karena terlalu gemas, Ucil pun membantu Dora untuk bangun");

    printf("*Tekan enter...*\n");
    _getch();
    system("cls");

    typewriting("Ucil\t: \"AGHHH!!\"");
    typewriting("Saat Ucil lengah, Dora melukai Ucil dengan pisau yang dia sembunyikan.");
    typewriting("\"MENJAUHLAH DARI RATU SELATAN\", ucap Dora dengan memberikan senyuman jahat yang lebar");
    typewriting("Ucil ketakutan, Ia langsung bersiap untuk bertarung dengan Dora");
    Sleep(1000);

    
}

// fungsi inii menampilkan epilogue
void epilogue(){
    system("cls");
    typewriting("Dora\t: \"UGH!! SIAL!!!\"");
    typewriting("Dora\t: \"AKU!?!?!? SEORANG GUARDIAN ANGEL DIKALAHKAN OLEH BOCAH SEPERTIMU?!?!?!\"");
    typewriting("Ucil\t: \"Kau menyebut dirimu Guardian Angel? Kau bahkan tampak seperti Dora the Explorer! Siapa sebenernya dirimu!?\"");
    typewriting("Dengan suara lirih kesakitan, Dora pun memperkenalkan dirinya.");
    typewriting("Dora\t: \"Aku sudah bilang kalau namaku Dora! Guardian Angel dari Ratu Selatan.\"");
    typewriting("Dora\t: \"Kekuatanmu... Tidak mungkin kamu dari dunia ini!\"");
    typewriting("Ucil\t: \"Aku memang bukan dari sini. Aku tiba-tiba terbangun di dunia ini.\"");
    typewriting("Dora\t: \"Sudah kuduga. Kamu pasti merupakan The Magnificent Dragon Slayer of The Northern Hemisphere!!\"");
    typewriting("Ucil\t: \"The magnifisen doraemon selai of nonton... Aku tidak paham omonganmu!\"");
    typewriting("Dora\t: \"Aku tidak menyangka bahwa The Magnificent Dragon Slayer of the Northern Hemisphere merupakan orang bodoh!\"");
    typewriting("Ucil\t: \"HEY! Apa maksudmu bilang aku bodoh!?\"");
    typewriting("...");
    typewriting("Dora & Ucil\t: \"!!!\"");

    printf("*Tekan enter...*");
    _getch();
    system("cls");

    typewriting("???\t: \"B.E.R.I.S.I.K\"");
    typewriting("???\t: \"D.I.A.M.\"");
    typewriting("???\t: \"T.E.N.G.G.E.L.A.M\"");
    typewriting("Suara misterius tersebut tampak kesal karena pertengkaran Ucil dan Dora.");
    typewriting("Tiba-tiba, seluruh salju yang berada di kaki Ucil berubah menjadi air...");

    Sleep(500);
    system("cls");
    
    system("color 97");
    Sleep(2000);

    typewriting("Ucil\t: \"T-tolong!!\"");
    typewriting("Ucil tenggelam dalam lautan air... lagi...");
    typewriting("Tidak ada satupun yang bisa mendengar permintaan tolong dia...");
    typewriting("...");
    typewriting("...");
    typewriting("Ucil\t: \"Mama...\"");
    typewriting("???\t: \"x*@#*(\"");
    typewriting("???\t: \"B!@G&^n\"");
    typewriting("???\t: \"B@NGUN\"");
    typewriting("???\t: \"BANGUN!!! UCILL!!!\"");

    system("color 70");
    typewriting("*BYURR");
    typewriting("Ucil\t: \"BWUURRP!! GWAH!!!.\"");
    typewriting("Ucil\t: \"Toloong!! Aku tenggelam!!\"");
    typewriting("Mama\t: \"Siapa juga yang tenggelam. Nglindur ni anak. Cepetan ke kampus! udah jam berapa ini!?\"");

    printf("*Tekan enter...*");
    _getch();
    system("cls");

    typewriting("Ucil\t: \"Dora dimana!? Pedangku? Bagaimana dengan Ratu Selatan??\"");
    typewriting("Mama\t: \"Lu tadi sebelum tidur nonton Dora! Makanya tuh kebawa sampe mimpi. Udah sana cepetan siap-siap.\"");
    typewriting("Ucil hanya diam.. Tidak menyangka semua itu hanyalah mimpi...");
}

/*
    ======================AKHIR KUMPULAN FUNGSI STORY======================
*/

/*
    ======================KUMPULAN FUNGSI BATTLE======================
*/

// fungsi ini menampilkan kalimat yang diucapkan musuh ketika terkena damage dari Ucil
void ucapmusuh(int n){
    char ucapan[5][100] = {"Bagaimana bisa....", "Ouch! Itu sakit tau!", "Aku.. Tidak akan kalah!!","Ugh! Kau hanya beruntung bocah!","Tidak akan kubiarkan kamu melakukan itu lagi!"};
    char ucapkan[100];

    strcpy(ucapkan, musuh[musuhke].nama);
    strcat(ucapkan, "\t: ");
    strcat(ucapkan, ucapan[n]);
    typewriting(ucapkan);
}

// fungsi ini menentukan outcome dari aksi ucil dan juga aksi musuh
void bandingkan(int aksiucil, int aksimusuh){
    system("cls");
    if(aksiucil == 1){
        typewriting("Ucil memilih Melee!!");
        Sleep(500);
        if(aksimusuh == 1){
            typewriting("Musuh memilih Melee!!");
            Sleep(500);
            typewriting("PARRY!!");
            typewriting("Tidak ada yang terkena damage!!\n");
        }
        else if(aksimusuh == 2){
            typewriting("Musuh memilih Ranged!!");
            Sleep(500);
            typewriting("Ucil memberikan damage!!");
            musuh[musuhke].hp--;
            ucapmusuh(rand()%5);
        }
        else {
            typewriting("Musuh memilih Defend!!");
            Sleep(500);
            typewriting("Ucil menerima damage!!");
            ucil.hp--;
        }
    }
    else if(aksiucil == 2){
        typewriting("Ucil memilih Ranged!!");
        Sleep(500);
        if(aksimusuh == 1){
            typewriting("Musuh memilih Melee!!");
            Sleep(500);
            typewriting("Ucil menerima damage!!\n");
            ucil.hp--;
        }
        else if(aksimusuh == 2){
            typewriting("Musuh memilih Ranged!!");
            Sleep(500);
            typewriting("EVADE!!");
            typewriting("Tidak ada yang terkena damage!!");
        }
        else {
            typewriting("Musuh memilih Defend!!");
            Sleep(500);
            typewriting("Ucil memberikan damage!!");
            musuh[musuhke].hp--;
            ucapmusuh(rand()%5);
        }
    }
    else if(aksiucil == 3){
        typewriting("Ucil memilih Defend!!");
        Sleep(500);
        if(aksimusuh == 1){
            typewriting("Musuh memilih Melee!!");
            Sleep(500);
            typewriting("Ucil memberikan damage!!\n");
            musuh[musuhke].hp--;
            ucapmusuh(rand()%5);
        }
        else if(aksimusuh == 2){
            typewriting("Musuh memilih Ranged!!");
            Sleep(500);
            typewriting("Ucil menerima damage!!");
            ucil.hp--;
        }
        else {
            typewriting("Musuh memilih Defend!!");
            Sleep(500);
            typewriting("Hmm.. agak awkward ya!");
        }
    }
    else typewriting("AKSI TIDAK TERSEDIA!");
}

// fungsi ini mengecek apakah salah satu dari HP Ucil maupun musuh mencapai 0
bool cekkalah(){
    if(ucil.hp == 0 || musuh[musuhke].hp == 0){
        return 1;
    }
    return 0;
}

// fungsi ini menampilkan monolog ketika HP Ucil mencapai 0
void ucilkalah(){
    system("cls");
    typewriting("Ucil\t: UGH!!");
    typewriting("Ucil\t: Maafkan aku...");
}

// fungsi ini mengganti indeks dari struct musuh. Untuk mempersiapkan Ucil melawan musuh selanjutnya
void ucilmenang(){
    musuhke += 1;
}

void waktuhabis(){
    system("cls");
    typewriting("Terlalu Lama!!");
    typewriting("Ucil menerima damage!!");
    ucil.hp--;
}

// fungsi ini merupakan environment yang ditemui user pada setiap battle
bool battle(){
    tampilanbesar("M E M A S U K I   B A T T L E");
    init_ucil();
    init_musuh(musuhke);
    while(1){
        bool flag = false;
        displaystatus();
        printf("\nPilih aksi Ucil : ");
        clock_t start_time = clock();
        while (!_kbhit()) {
            clock_t current_time = clock();
            double time_taken = (double)(current_time - start_time) / CLOCKS_PER_SEC;
            if(time_taken == 5){
                printf("\n");
                typewriting("Musuh mulai mendekat...");
            }
            if(time_taken > 10) {
                waktuhabis();
                flag = true;
                break;
            }
        }
        if(flag){
            if(ucil.hp == 0){
                ucilkalah();
                return 0;
            }
            continue;
        }
        scanf("%d", &ucil.action);
        musuh[musuhke].action = rand()%3+1;
        bandingkan(ucil.action, musuh[musuhke].action);
        if(cekkalah()){
            if(ucil.hp == 0){
                ucilkalah();
                return 0;
            }
            else {
                ucilmenang();
                return 1;
            }
        }
    }
}

void tutorial(){
    int pilihan;
    system("cls");
    typewriting("Tampilkan tutorial?");
    printf("1.Ya\n2.Tidak\n>> ");
    scanf("%d", &pilihan);
    if(pilihan == 1){
        typewriting("Akan terdapat 3 aksi:\n1.Melee\n2.Ranged\n3.Defend");
        typewriting("Melee menang melawan ranged\nRanged menang melawan defend\nDefend menang melawan melee.");
        typewriting("Contoh:\n\nJika ucil memilih 1.Melee, dan musuh memilih 2.Ranged, maka Ucil menang, dan HP musuh akan berkurang 1. Begitupula sebaliknya.");
        typewriting("Ucil dan musuh masing-masing memiliki 3 HP. Jika HP Ucil mencapai 0. Maka Ucil kalah dan permainan berakhir.");
        typewriting("Jika Ucil tidak kunjung melakukan sebuah aksi. Maka musuh akan semakin mendekat.");
        typewriting("Ucil harus segera menentukan aksinya atau dia akan diserang karena lengah.");
        typewriting("Selamat bermain!");

        printf("*Tekan enter...*");
        _getch();
        system("cls");
    }
    else if(pilihan == 2){
        return;
    }
    else typewriting("Tolong input 1 atau 2 saja!");
}

/*
    ======================AKHIR KUMPULAN FUNGSI BATTLE======================
*/
//Tambahkan hasil display

int main()
{
    srand(time(NULL));
    int pilihanprologue;
    startingscreen();
    system("cls");
    Sleep(400);
    typewriting("Tampilkan prologue?");
    printf("1.Ya\n>> ");
    scanf("%d", &pilihanprologue);
    if(pilihanprologue == 1){
        prologue();
    }
    goblinencounter();
    tutorial();
    if(battle()){
        doraencounter();
        if(battle()){
            epilogue();
            theend();
            return 0;
        }
    }
    gameover();
    epilogue();
    return 0;
}
