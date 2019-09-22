/* Lab01
   組別 : 3
   組員 : 10727204 古沛彤 10727247 廖仁傑 */ 
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

bool gtest = false ; // 如果遞迴超過20000次 值會變true 
unsigned long long gtimes = 0 ; // 如果遞迴超過20000次 會暫存於此 
void type1( unsigned long long testnum ) { // 呼叫迴圈的function 
	unsigned long long nownum = 1, frontnum = 0 ; // 現在的費式數 ， 上一個費式數 
	unsigned long long temp = 0, sqrtnum = 0 ; // 暫存用 ， 開根號後的值 
	unsigned long long outertimes = 0, innertimes = 0 ; // 外迴圈次數 ， 內迴圈次數 
	unsigned long long firstroot = 0, secondroot = 0 ; // 第一個因數 ， 第二個因數 
	if ( testnum == 0 ) // 0-92輸入0時 
	    cout << '\n' << "### Number must be in [1,92] ###" << endl ;
	else {
		for ( unsigned long long count = 1 ; count <= testnum ; count++ ) { // 外迴圈進行費式數列計算 
			outertimes++ ; // 計算外迴圈進行次數 
			temp = nownum ; // nownum暫存於temp 
			nownum += frontnum ;  // nownum為新的費式數 
			frontnum = temp ; // 更新上一個費式數 
			cout << "[  "<< count << "] " << nownum << " = " ;
		
			sqrtnum = (unsigned long long) sqrt( nownum ) ; // 計算費式數開根號的值 
			for ( unsigned long long j = sqrtnum ; j >= 1 ; j-- ) { // 內迴圈 由根號值找費式數相差最近的兩個因數 
				if ( nownum % j == 0 ) { // 找到後設定第一因數和第二因數 
					firstroot = j ; // 設定第 一因數 
					secondroot = nownum / j ; // 設定第二因數 
					break ; // 跳出迴圈的條件 
				} // if
			 
		        innertimes++ ; // 計算內迴圈進行次數 
			} // for
			cout << firstroot << "*" << secondroot << "       (Inner loop: " << innertimes << " times)" << '\n' ;
			innertimes = 0 ; 
		} // for
	
		outertimes-- ;
		cout << "<Outer recursion: " << outertimes << ">" << endl ;
	} // else
	
} // type1

bool findroot( unsigned long long fnum, unsigned long long &runtimes, unsigned long long &sqrtnum ) { // 找費式數的因數 
	bool returnvalue = true ; // 最後function的回傳值 
	unsigned long long firstroot = 0, secondroot = 0 ; // 第一因數 ， 第二因數 
	if ( fnum % sqrtnum == 0 ) { // 找到後設定第一因數和第二因數  
		firstroot = sqrtnum ; // 設定第一因數
		secondroot = fnum / sqrtnum ; // 設定第二因數
		cout << firstroot << "*" << secondroot << "       (Inner recursion: "  ;
	} // if
	else {
		runtimes++ ; // 內遞迴數+1 
		sqrtnum-- ; // 根號值-1 
		if ( runtimes >= 20000 ) // 內遞迴數>=20000時 
		    return false ; // 回傳false 
		else // 內遞迴數<20000時 
			returnvalue = findroot( fnum, runtimes, sqrtnum ) ; // 再遞迴一次，呼叫findroot 
	} // else
		    
	return returnvalue ;
} // findroot()

void openOrcloserecursion( unsigned long long fnum, unsigned long long &runtimes, unsigned long long &sqrtnum ) { // 避免遞迴次數大於20000的function 
	
	if ( !findroot( fnum, runtimes, sqrtnum )  ) { // 遞迴次數大於20000時 
		gtest = true ; // 確定遞迴次數大於20000 
		gtimes += runtimes ; // 設定總遞迴數 
		runtimes = 0 ;  
		if ( gtimes >= 10000000 )
		    cout << "   (Inner recursion: more than   10000000 times)" << endl ;
		else // 若總遞迴數<10000000 
			openOrcloserecursion( fnum, runtimes, sqrtnum ) ; // 再遞迴一次 ， 呼叫 openOrcloserecursion
	} // if 
	else { // // 遞迴次數小於20000時  
		if ( gtest ) {  // 確定遞迴次數大於20000 
			gtimes += runtimes ; // 設定總遞迴數  
			cout << gtimes << " times)" << endl ;
		} // else
		else {
			cout << runtimes << " times)" << endl ;
		} // else 
		
	} // else
	
	gtest = false ; // 初始化 
	gtimes = 0 ; // 初始化 
} // openOrcloserecursion()

void totalFibonacci( unsigned long long qtestnum, unsigned long long temp, unsigned long long nownum, unsigned long long frontnum, unsigned long long times ) { // 計算費式數的遞迴function 
	unsigned long long sqrtnum = 0, calltimes = 1 ; // 開根號值，內遞迴次數 
	if ( qtestnum == 0 ) // 0-92輸入0時  
	    cout << '\n' << "### Number must be in [1,92] ###" << endl ;
	else if ( qtestnum >= 1 ) {
	    temp = nownum ; // nownum暫存於temp  
		nownum += frontnum ; // nownum為新的費式數  
		frontnum = temp ; // 更新上一個費式數  
	    cout << "[  "<< times << "] " << nownum << " = " ;
	    sqrtnum = (unsigned long long) sqrt( nownum ) ; // 計算nownum開根號值 
	        openOrcloserecursion( nownum, calltimes, sqrtnum ) ; // 呼叫 openOrcloserecursion的function 
	    
	    if ( times < qtestnum ) {  // 尚未達到要求費式數 
		    times++ ;
	        totalFibonacci( qtestnum, temp, nownum, frontnum, times ) ; // 呼叫 totalFibonacci
	    } // if
	    else
	        cout << "<Outer recursion: " << times << ">" << endl ;
	} // else
	        
} // totalFibonacci() 



int main(int argc, char** argv) {
	unsigned long long testnumber = 0, command = 0 ; // 0-92的數字 ， 3種類型中的0.1.2 
	unsigned long long nownumber = 1 , frontnumber = 0, tempnumber = 0 ; // 現在的費式數 ， 上一個費式數 ， 暫存 
	unsigned long long outertimes = 1 ; // 呼叫function的外迴圈參數 
	cout << "** Fibonacci Series Generator **" << '\n' << "* 0. Quit                      *" << '\n'
	     << "* 1. Iterative generation      *" << '\n' << "* 2. Recursive generation      *" << '\n' 
	     << "********************************" << '\n' << '\n' << "Input a command(0, 1, 2): "  ;
	cin >> command ; // 選擇輸入選項數字 
	
	while( 1 ) { // 使用者會輸入數字直到0為止 
	
		if ( command == 0 ) // 如果command為0時直接離開 
		    break ;
	  	if ( command == 1 ){ // 如果command是1時 
	  		cout << '\n' << '\n' << "Input a number(0-92): " ;
	        cin >> testnumber ; // 輸入0-92的數字 
	        while ( testnumber > 92 || testnumber < 0 ) { // 如果testnumber不是0-92間的整數，持續輸入直到為0-92 
	            cout << '\n' << '\n' << "Number not in range!" << '\n' << endl ;
	            cout << '\n'<< "Input a number(0-92): " ;
	            cin >> testnumber ; // 輸入0-92的數字 
	        } // while 
	        
	        type1( testnumber ) ; // 呼叫迴圈的function 
	    } // if
		else if ( command == 2 ){ // 如果command是2時  
			cout << '\n' << '\n' << "Input a number(0-92): " ;
			cin >> testnumber ; // 輸入0-92的數字 
			while ( testnumber > 92 || testnumber < 0 ) { // 如果testnumber不是0-92間的整數，持續輸入直到為0-92  
	            cout << '\n' << '\n' << "Number not in range!" << '\n' << endl ;
	            cout << '\n' << "Input a number(0-92): " ;
	            cin >> testnumber ; // 輸入0-92的數字 
	        } // while 
	        
			totalFibonacci( testnumber, tempnumber, nownumber, frontnumber, outertimes ) ;// 呼叫遞迴的function 
		} // else if
		
		if ( command != 0 && command != 1 && command != 2 ) // 如果command不是0或1或2 
		    cout << '\n' << "Command does not exist!" << endl ;
		cout << '\n' ;
		cout << "** Fibonacci Series Generator **" << '\n' << "* 0. Quit                      *" << '\n'
	         << "* 1. Iterative generation      *" << '\n' << "* 2. Recursive generation      *" << '\n' 
	     	 << "********************************" << '\n' << '\n' << "Input a command(0, 1, 2): " ;
		cin >> command ; // 輸入新的command 
	} // while
	
	
	
} // main()

















