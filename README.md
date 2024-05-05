tioRestore
========
**tioRestore** is two programs that I made at 1:30am while extremely angry at a
certain program for not correctly restoring my termios. At the time the
libraries depended by that program were broken, and so I wrote these.

Usage
-----
```
$ tiosave
some other stuff
$ tiolaod
```

Info
----
**tio(save/load)** save and load the current `stdin termios` to the file
specified in `SAVELOC` at compile time.

Exit Status
-----------
9 is returned on file read/write errors, everything else is determined
by errno as set by `fopen` and `fread/write`.

Customization
-------------
`INSTALLLOC` and `SAVELOC` control the install location and the location
to save the termios to, both can be found in `config.mk`.
