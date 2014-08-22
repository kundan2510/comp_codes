g := (x,m) -> x^m - 1;
h := (x,y,a) -> x^2 + y^2 - 2*x*y - a;

myFunc := proc(p,a,lg)
begin
    f1 := poly(g(x,(p-1)/2),[x]);
    f2 := poly(h(x,y,a),[x]);
    print(f1);
    print(f2);
    r := divide(f1,f2,Rem);
    print(r);
    c1 := coeff(r , 1);
    c2 := coeff(r , 0);
    print(c1);
    print(c2);
    r1 := divide(c1,g(y,lg),[y],Rem);
    r2 := divide(c2,g(y,lg),[y],Rem);
    print(r1);
    print(r2);
    r3 := poly(r1,[y],IntMod(p));
    r4 := poly(r2,[y],IntMod(p));
    print(r3);
    print(r4);
    n1 := poly(r3,Expr)*x + poly(r4,Expr);
    print(n1);
    n2 := poly(n1,[x]);
    print(n2);
    n3 := divide(f2,n2,Rem);
    print(n3);
end_proc
    
    
    

