socat -v TCP-LISTEN:20169,fork exec:'/bin/cat'
socat TCP-LISTEN:20169,fork,reuseaddr -