/*

a1 a2 ... ak ... an ... a2n

a2n-k = ak+1

dk = 
		(ak - al) + ... + (ak - ak-1) + (ak - ak)
		+
		(ak+1 - ak) + ... + (a2n-ak)

	=	 k*(ak) - (a1 + ... + ak) + (ak+1 + ... + a2n) - (2n-k)*ak 

	= 	 -2*(a1 + ... +ak)	- 2(n-k)*ak

dk+1 	= dk + -2*ak+1 + 2(n-k)*ak - 2(n-k-1)*ak+1
		= dk + 2(n-k)(ak-ak+1)

80 56 48 40 40 48 56 80
  -24 -8 -8  0   8  8  24
(dk+1 - dk) should be divisible by 2(n-k)
  -6  -4  											

d2n-k = 	-2*(a1 + ... +ak) + 2(n - k)*ak+1
			
d2n-(k-1) = -2*(a1 + ... + ak-1) + 2(n-k+1))*ak 



*/