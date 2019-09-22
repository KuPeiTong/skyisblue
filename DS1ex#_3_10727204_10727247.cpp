/* Lab01
   �էO : 3
   �խ� : 10727204 �j�K�� 10727247 ������ */ 
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

bool gtest = false ; // �p�G���j�W�L20000�� �ȷ|��true 
unsigned long long gtimes = 0 ; // �p�G���j�W�L20000�� �|�Ȧs�� 
void type1( unsigned long long testnum ) { // �I�s�j�骺function 
	unsigned long long nownum = 1, frontnum = 0 ; // �{�b���O���� �A �W�@�ӶO���� 
	unsigned long long temp = 0, sqrtnum = 0 ; // �Ȧs�� �A �}�ڸ��᪺�� 
	unsigned long long outertimes = 0, innertimes = 0 ; // �~�j�馸�� �A ���j�馸�� 
	unsigned long long firstroot = 0, secondroot = 0 ; // �Ĥ@�Ӧ]�� �A �ĤG�Ӧ]�� 
	if ( testnum == 0 ) // 0-92��J0�� 
	    cout << '\n' << "### Number must be in [1,92] ###" << endl ;
	else {
		for ( unsigned long long count = 1 ; count <= testnum ; count++ ) { // �~�j��i��O���ƦC�p�� 
			outertimes++ ; // �p��~�j��i�榸�� 
			temp = nownum ; // nownum�Ȧs��temp 
			nownum += frontnum ;  // nownum���s���O���� 
			frontnum = temp ; // ��s�W�@�ӶO���� 
			cout << "[  "<< count << "] " << nownum << " = " ;
		
			sqrtnum = (unsigned long long) sqrt( nownum ) ; // �p��O���ƶ}�ڸ����� 
			for ( unsigned long long j = sqrtnum ; j >= 1 ; j-- ) { // ���j�� �Ѯڸ��ȧ�O���Ƭۮt�̪񪺨�Ӧ]�� 
				if ( nownum % j == 0 ) { // ����]�w�Ĥ@�]�ƩM�ĤG�]�� 
					firstroot = j ; // �]�w�� �@�]�� 
					secondroot = nownum / j ; // �]�w�ĤG�]�� 
					break ; // ���X�j�骺���� 
				} // if
			 
		        innertimes++ ; // �p�⤺�j��i�榸�� 
			} // for
			cout << firstroot << "*" << secondroot << "       (Inner loop: " << innertimes << " times)" << '\n' ;
			innertimes = 0 ; 
		} // for
	
		outertimes-- ;
		cout << "<Outer recursion: " << outertimes << ">" << endl ;
	} // else
	
} // type1

bool findroot( unsigned long long fnum, unsigned long long &runtimes, unsigned long long &sqrtnum ) { // ��O���ƪ��]�� 
	bool returnvalue = true ; // �̫�function���^�ǭ� 
	unsigned long long firstroot = 0, secondroot = 0 ; // �Ĥ@�]�� �A �ĤG�]�� 
	if ( fnum % sqrtnum == 0 ) { // ����]�w�Ĥ@�]�ƩM�ĤG�]��  
		firstroot = sqrtnum ; // �]�w�Ĥ@�]��
		secondroot = fnum / sqrtnum ; // �]�w�ĤG�]��
		cout << firstroot << "*" << secondroot << "       (Inner recursion: "  ;
	} // if
	else {
		runtimes++ ; // �����j��+1 
		sqrtnum-- ; // �ڸ���-1 
		if ( runtimes >= 20000 ) // �����j��>=20000�� 
		    return false ; // �^��false 
		else // �����j��<20000�� 
			returnvalue = findroot( fnum, runtimes, sqrtnum ) ; // �A���j�@���A�I�sfindroot 
	} // else
		    
	return returnvalue ;
} // findroot()

void openOrcloserecursion( unsigned long long fnum, unsigned long long &runtimes, unsigned long long &sqrtnum ) { // �קK���j���Ƥj��20000��function 
	
	if ( !findroot( fnum, runtimes, sqrtnum )  ) { // ���j���Ƥj��20000�� 
		gtest = true ; // �T�w���j���Ƥj��20000 
		gtimes += runtimes ; // �]�w�`���j�� 
		runtimes = 0 ;  
		if ( gtimes >= 10000000 )
		    cout << "   (Inner recursion: more than   10000000 times)" << endl ;
		else // �Y�`���j��<10000000 
			openOrcloserecursion( fnum, runtimes, sqrtnum ) ; // �A���j�@�� �A �I�s openOrcloserecursion
	} // if 
	else { // // ���j���Ƥp��20000��  
		if ( gtest ) {  // �T�w���j���Ƥj��20000 
			gtimes += runtimes ; // �]�w�`���j��  
			cout << gtimes << " times)" << endl ;
		} // else
		else {
			cout << runtimes << " times)" << endl ;
		} // else 
		
	} // else
	
	gtest = false ; // ��l�� 
	gtimes = 0 ; // ��l�� 
} // openOrcloserecursion()

void totalFibonacci( unsigned long long qtestnum, unsigned long long temp, unsigned long long nownum, unsigned long long frontnum, unsigned long long times ) { // �p��O���ƪ����jfunction 
	unsigned long long sqrtnum = 0, calltimes = 1 ; // �}�ڸ��ȡA�����j���� 
	if ( qtestnum == 0 ) // 0-92��J0��  
	    cout << '\n' << "### Number must be in [1,92] ###" << endl ;
	else if ( qtestnum >= 1 ) {
	    temp = nownum ; // nownum�Ȧs��temp  
		nownum += frontnum ; // nownum���s���O����  
		frontnum = temp ; // ��s�W�@�ӶO����  
	    cout << "[  "<< times << "] " << nownum << " = " ;
	    sqrtnum = (unsigned long long) sqrt( nownum ) ; // �p��nownum�}�ڸ��� 
	        openOrcloserecursion( nownum, calltimes, sqrtnum ) ; // �I�s openOrcloserecursion��function 
	    
	    if ( times < qtestnum ) {  // �|���F��n�D�O���� 
		    times++ ;
	        totalFibonacci( qtestnum, temp, nownum, frontnum, times ) ; // �I�s totalFibonacci
	    } // if
	    else
	        cout << "<Outer recursion: " << times << ">" << endl ;
	} // else
	        
} // totalFibonacci() 



int main(int argc, char** argv) {
	unsigned long long testnumber = 0, command = 0 ; // 0-92���Ʀr �A 3����������0.1.2 
	unsigned long long nownumber = 1 , frontnumber = 0, tempnumber = 0 ; // �{�b���O���� �A �W�@�ӶO���� �A �Ȧs 
	unsigned long long outertimes = 1 ; // �I�sfunction���~�j��Ѽ� 
	cout << "** Fibonacci Series Generator **" << '\n' << "* 0. Quit                      *" << '\n'
	     << "* 1. Iterative generation      *" << '\n' << "* 2. Recursive generation      *" << '\n' 
	     << "********************************" << '\n' << '\n' << "Input a command(0, 1, 2): "  ;
	cin >> command ; // ��ܿ�J�ﶵ�Ʀr 
	
	while( 1 ) { // �ϥΪ̷|��J�Ʀr����0���� 
	
		if ( command == 0 ) // �p�Gcommand��0�ɪ������} 
		    break ;
	  	if ( command == 1 ){ // �p�Gcommand�O1�� 
	  		cout << '\n' << '\n' << "Input a number(0-92): " ;
	        cin >> testnumber ; // ��J0-92���Ʀr 
	        while ( testnumber > 92 || testnumber < 0 ) { // �p�Gtestnumber���O0-92������ơA�����J���쬰0-92 
	            cout << '\n' << '\n' << "Number not in range!" << '\n' << endl ;
	            cout << '\n'<< "Input a number(0-92): " ;
	            cin >> testnumber ; // ��J0-92���Ʀr 
	        } // while 
	        
	        type1( testnumber ) ; // �I�s�j�骺function 
	    } // if
		else if ( command == 2 ){ // �p�Gcommand�O2��  
			cout << '\n' << '\n' << "Input a number(0-92): " ;
			cin >> testnumber ; // ��J0-92���Ʀr 
			while ( testnumber > 92 || testnumber < 0 ) { // �p�Gtestnumber���O0-92������ơA�����J���쬰0-92  
	            cout << '\n' << '\n' << "Number not in range!" << '\n' << endl ;
	            cout << '\n' << "Input a number(0-92): " ;
	            cin >> testnumber ; // ��J0-92���Ʀr 
	        } // while 
	        
			totalFibonacci( testnumber, tempnumber, nownumber, frontnumber, outertimes ) ;// �I�s���j��function 
		} // else if
		
		if ( command != 0 && command != 1 && command != 2 ) // �p�Gcommand���O0��1��2 
		    cout << '\n' << "Command does not exist!" << endl ;
		cout << '\n' ;
		cout << "** Fibonacci Series Generator **" << '\n' << "* 0. Quit                      *" << '\n'
	         << "* 1. Iterative generation      *" << '\n' << "* 2. Recursive generation      *" << '\n' 
	     	 << "********************************" << '\n' << '\n' << "Input a command(0, 1, 2): " ;
		cin >> command ; // ��J�s��command 
	} // while
	
	
	
} // main()

















