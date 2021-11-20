#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include "libft.h"

int main(void)
{
//**************************//	
//	char	buf2[15] = "";	//
//	char	buf1[15] = "";	//
//	int		dstsize;		//
//							//	varmachine
//	ft_memset(buf1, 0, 15);	//
//	ft_memset(buf2, 0, 15);	//
//	ft_memset(buf1, 'r', 6);//
//	ft_memset(buf2, 'r', 6);//
//**************************//
//	char	*src = "lorem";	//
//	buf1[11] = 'a';			//	test1
//	buf2[11] = 'a';			//
//	dstsize = 15;			//
//**************************//

//**********************//
//	char	*src = "";	//		test2
//	dstsize = 15;		//
//**********************//

//**********************************//
//	char	*src = "lorem ipsum";	// 
//	buf1[0] = '\0';					//
//	buf2[0] = '\0';					//	test3
//	buf1[11] = 'a';					//
//	buf2[11] = 'a';					//
//	dstsize = 15;					//
//**********************************//

//**********************************************//	
//	char	*src = "lorem ipsum dolor sit amet";//
//	buf1[14] = 'a';								// test4
//	buf2[14] = 'a';								//
//	dstsize = 15;								//
//**********************************************//	

//**********************************************//	
//	char	*src = "lorem ipsum dolor sit amet";//
//	buf1[10] = 'a';								// test5
//	buf2[10] = 'a';								//
//	dstsize = 0;								//
//**********************************************//	

//**********************************************//	
//	char	*src = "lorem ipsum dolor sit amet";//
//	buf1[10] = 'a';								// test6
//	buf2[10] = 'a';								//
//	dstsize = 1;								//
//**********************************************//	

//**********************************************//	
//	char	*src = "lorem ipsum dolor sit amet";//
//	ft_memset(buf2, 'l', 15);					//
//	ft_memset(buf1, 'r', 15);					//
//	buf1[0] = '*';								// test7
//	dstsize = 5;								//
//**********************************************//	

//**********************************************//	
//	char	*src = "lorem ipsum dolor sit amet";//
//	buf1[10] = 'a';								//
//	buf2[10] = 'a';								// test8
//	dstsize = 6;								//
//**********************************************//	

//**********************************************//	
//	char	*src = "lorem ipsum dolor sit amet";//
//	ft_memset(buf2, 'r', 14);					//
//	ft_memset(buf1, 'r', 14);					// test9
//	dstsize = 15;								//
//**********************************************//	

	char	buf1[30];
	char	buf2[30];
	memset(buf1, 0, 30);
	memset(buf2, 0, 30);
	char	*src = (char *)"AAAAAAAAA";
	int		dstsize;

//***********************//
	memset(buf1, 'C', 5);//
	memset(buf2, 'C', 5);//
	dstsize = -1;		//
//***********************//

	printf("My:\t%lu\t%s\n", ft_strlcat(buf2, src, dstsize), buf2);
	printf("Orig:\t%lu\t%s\n", strlcat(buf1, src, dstsize), buf1);
	return(0);
}
