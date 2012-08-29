BEGIN { blanks = 0;  nonblanks = 0; tempno = -1; flag = 1; s = ""; 
        nln ="\n"; }

$0 == "" && flag { blanks++;  }

$0 != "" && flag  { 
            nonblanks++;
            if (nonblanks > 2) {
            	if (tempno == -1)
                  tempno = blanks;
                if (blanks > tempno)
                  flag = 0;
                else {
                  if (s == "")
                    s = "*" nln $0;
                  else 
                   s = s nln $0; } } }

END { print s }
