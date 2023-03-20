    #include <stdio.h>
    
    main(){
    
        int a, b, c ,d ,e;
    
        scanf("%d", &a);
        scanf("%d", &b);
    
        if(a < b)
         {if(a%2 != 0)
          {a=a + 1;}
         if(b%2 != 0)
          {b=b + 1;}
         if (a != 0)
          {c=((a/2)+(a/2)*3) ;}
          else {c=0;}
         if (b != 0)
          {d=((b/2)+(b/2)*3) ;}
          else {d=0;}}
            else {if(a%2 != 0)
            {a=a+1;}
            if(b%2 != 0)
            {b=b+1;}
            if(a!= 0)
            {c =((a/2)+(a/2)*3) ;}
            else {c=0;}
            if (b != 0)
            {d =((b/2)+(b/2)*3) ;}
            else {d=0;}}
            e = c + d
            printf("%d\n%d\n%d",c ,d ,e);
            return 0;
            
    }
