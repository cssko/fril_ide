from itertools import zip_longest, starmap
def grouper(iterable, n, fillvalue=None):
    "Collect data into fixed-length chunks or blocks"
    # grouper('ABCDEFG', 3, 'x') --> ABC DEF Gxx"
    args = [iter(iterable)] * n
    return zip_longest(*args, fillvalue=fillvalue)

bip_list = """abort
addcl
and
atomic
cd
cdict
charof
cl
close
complement
con
conj
convert
cos
cprintf
cputime
create
create_a
create_r
create_ra
cscanf
date
ddict
def
def_dtype
def_itype
def_rel
delcl
dempdict
dempster
dict
disj
division
dtype
dtype_name
dtype_to_freq
dtype_to_list
dynamic
edict
eq
errm
error
err_han
evlog
exists
exit
exp
expected_value
export
fail
fdict
file
filebcopy
filename
filepos
filesearch
findall
flush
fmem
forall
fset
fsetdict
fset_name
gen
general
gensym
get
getb
getenv
get_prior
get_univ
help
help_example
idict
if
import
init_random
int
intersection
intok
isall
itype
itype_name
itype_to_freq
itype_to_list
kb_garbage
kill
less
less_eq
list
listfile
lload
load
lreload
match
maximise_frame
mdict
module
module_initialisation
name
neg
negg
nospy
not
num
oh
open
or
orr
os
osc
ose
osv
p
peek
peekb
point_match
poss_match
power
pp
ppq
pq
prlen
pspaces
putb
qh
qs
qsc
qse
qsv
r
random
rdict
read
read_suppterm
reload
remainder
repeat
sc
se
set
setenv
set_difference
sh
sin
snips
spy
spying
square
statistics
stricteq
stringof
str_to_list
sum
supp_collect
supp_expect
supp_query
supp_value
sv
sys
system_garbage
tan
tempfile
times
tq
true
truncate
union
univ
univdict
univ_name
var
visible
w
wh
wq
write
writeq
ws
wse
wsc
wspaces
wsv
tq
?
!
_
\\|"""
bip_list = bip_list.split("\n")
prepped_bip_list = [f'QStringLiteral("\\\\b{bip}\\\\b"),' for bip in bip_list]
# longest_bip = max(map(lambda bip: len(bip), prepped_bip_list))
# longest_bip += 1 # Accounting for commas
x = list(grouper(prepped_bip_list, 2))
longest_ = max(map(lambda x: len(x[0]), x))

def f(a, l):
    return f"{a:<{l}}" 

def format_line(*args):
    return f"{f(args[0], longest_)}{args[1]}"

for l in x:
    print(format_line(*l))

