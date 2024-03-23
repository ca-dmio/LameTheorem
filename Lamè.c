#include <stdio.h>

int main(void){

	int n, i, var, count, a, b ;
	
	do {                                                              //Type the number to test for Lamé's theorem
		printf("Type a POSITIVE integer:");
		scanf("%d", &n);
	} while (n <= 0);
	
	int f_i = 1, f_prec = 1 ;                                         // Evaluate the (n+1)th and (n+2)th Fibonacci's numbers 
	for (i = 3; i <= n+2; i++){
		var = f_i ;
		f_i += f_prec ;
		f_prec = var ;
	}

	printf("F(%d)=%d and F(%d)=%d \n", n+2, f_i, n+1, f_prec); 
	printf("The gcd(%d,%d)=", f_i, f_prec);

	for(i = 2; i <= f_i; i++){                                       // check how long euclid's algorithm takes for all the couples until it takes n divisions
		for(int m = 1; m < i && count < n; m++){
			a = i, b = m;
			count = 0;
			while(b != 0){
				var = b ;
				b = a % b ;
				a = var ;
				count += 1 ;
			}
			//printf("%d, %d    %d\n", l, m, count);         
			if(count >= n && i != f_i && m != f_prec){        //if it's a different couple than the (n+1)th and (n+2)th Fibonacci's numbers you disproved Lamè
				printf("Lamè was wrong the gcd(%d,%d) is computed in %d computations\n", i, m, count);
				return -1;
			}
			else if(i == f_i && m == f_prec){                  // otherwide printe the couple, the gcd and the number of divisions it has taken to compute it
				printf("%d, computed in %d divisions\nAll of the previouses couples computate in less divisions\n", a, count);
			}
		}
	}
	printf("Lamè's theorem is true for n=%d\n", n);
	
	return 0 ;
}
