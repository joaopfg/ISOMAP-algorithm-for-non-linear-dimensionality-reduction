test = fopen('Result.txt','r');
A = fscanf(test,'%f',[2000 Inf]);
fclose(test);

fid = fopen ('FinalResult.txt','w');
H = zeros(2000);

for i = 1:2000
  for j = 1:2000
    if(i == j) H(i,j) += 1;
    endif
  H(i,j) -= 1/2000;
  endfor
endfor

T = -(H*A*H)/2;
[V,D] = eig(T);
v = sort(diag(D));
y1 = sqrt(v(2000,1))*V(:,2000);
y1 = y1.';
y2 = sqrt(v(1999,1))*V(:,1999);
fprintf(fid,'%f %f\n',y1,y2);
y2 = y2.';
plot(y1,y2,'o');
xlabel("x");
ylabel("y");
title("2D embedding");
fclose (fid);
