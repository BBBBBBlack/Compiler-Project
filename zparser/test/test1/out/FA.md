## 产生式

- program → basic id ( ) block 
- block → { decls stmts } 
- decls → decls decl 
- decls → ε 
- decl → type id ; 
- type → type [ num ] 
- type → basic 
- basic → float 
- basic → int 
- stmts → stmts stmt 
- stmts → ε 
- stmt → id = expr ; 
- stmt → loc = expr ; 
- stmt → if ( bool ) stmt 
- stmt → if ( bool ) stmt else stmt 
- stmt → while ( bool ) stmt 
- stmt → do stmt while ( bool ) ; 
- stmt → break ; 
- stmt → block 
- loc → loc [ num ] 
- loc → id 
- bool → bool || join 
- bool → join 
- join → join && equality 
- join → equality 
- equality → equality == rel 
- equality → equality != rel 
- equality → rel 
- rel → expr < expr 
- rel → expr <= expr 
- rel → expr >= expr 
- rel → expr > expr 
- rel → expr 
- expr → expr + term 
- expr → expr - term 
- expr → term 
- term → term * unary 
- term → term / unary 
- term → unary 
- unary → ! unary 
- unary → - unary 
- unary → factor 
- factor → ( expr ) 
- factor → loc 
- factor → id 
- factor → num 
- factor → real 
- factor → true 
- factor → false 
- START → program 

## FA Graph

```mermaid
	graph LR
	node0("<div>I0:<br>basic → ·int <br>basic → ·float <br>program → ·basic id ( ) block <br>START → ·program <br></div>")
	node0--> |"float"| node4
	node0--> |"program"| node3
	node0--> |"basic"| node2
	node0--> |"int"| node1
	node1("<div>I1:<br>basic → int ·<br></div>")
	node2("<div>I2:<br>program → basic ·id ( ) block <br></div>")
	node2--> |"id"| node5
	node3("<div>I3:<br>START → program ·<br></div>")
	node4("<div>I4:<br>basic → float ·<br></div>")
	node5("<div>I5:<br>program → basic id ·( ) block <br></div>")
	node5--> |"("| node6
	node6("<div>I6:<br>program → basic id ( ·) block <br></div>")
	node6--> |")"| node7
	node7("<div>I7:<br>block → ·{ decls stmts } <br>program → basic id ( ) ·block <br></div>")
	node7--> |"{"| node9
	node7--> |"block"| node8
	node8("<div>I8:<br>program → basic id ( ) block ·<br></div>")
	node9("<div>I9:<br>decls → ε ·<br>decls → ·decls decl <br>block → { ·decls stmts } <br></div>")
	node9--> |"decls"| node10
	node10("<div>I10:<br>basic → ·float <br>type → ·basic <br>decl → ·type id ; <br>basic → ·int <br>stmts → ε ·<br>stmts → ·stmts stmt <br>type → ·type [ num ] <br>block → { decls ·stmts } <br>decls → decls ·decl <br></div>")
	node10--> |"float"| node4
	node10--> |"basic"| node12
	node10--> |"stmts"| node14
	node10--> |"int"| node1
	node10--> |"decl"| node13
	node10--> |"type"| node11
	node11("<div>I11:<br>type → type ·[ num ] <br>decl → type ·id ; <br></div>")
	node11--> |"id"| node16
	node11--> |"["| node15
	node12("<div>I12:<br>type → basic ·<br></div>")
	node13("<div>I13:<br>decls → decls decl ·<br></div>")
	node14("<div>I14:<br>loc → ·loc [ num ] <br>stmt → ·block <br>stmt → ·break ; <br>stmt → ·do stmt while ( bool ) ; <br>stmt → ·while ( bool ) stmt <br>block → ·{ decls stmts } <br>stmt → ·if ( bool ) stmt else stmt <br>stmt → ·if ( bool ) stmt <br>stmt → ·loc = expr ; <br>loc → ·id <br>block → { decls stmts ·} <br>stmt → ·id = expr ; <br>stmts → stmts ·stmt <br></div>")
	node14--> |"id"| node24
	node14--> |"do"| node25
	node14--> |"stmt"| node21
	node14--> |"}"| node22
	node14--> |"block"| node20
	node14--> |"break"| node19
	node14--> |"while"| node18
	node14--> |"if"| node23
	node14--> |"{"| node9
	node14--> |"loc"| node17
	node15("<div>I15:<br>type → type [ ·num ] <br></div>")
	node15--> |"num"| node26
	node16("<div>I16:<br>decl → type id ·; <br></div>")
	node16--> |";"| node27
	node17("<div>I17:<br>stmt → loc ·= expr ; <br>loc → loc ·[ num ] <br></div>")
	node17--> |"["| node29
	node17--> |"="| node28
	node18("<div>I18:<br>stmt → while ·( bool ) stmt <br></div>")
	node18--> |"("| node30
	node19("<div>I19:<br>stmt → break ·; <br></div>")
	node19--> |";"| node31
	node20("<div>I20:<br>stmt → block ·<br></div>")
	node21("<div>I21:<br>stmts → stmts stmt ·<br></div>")
	node22("<div>I22:<br>block → { decls stmts } ·<br></div>")
	node23("<div>I23:<br>stmt → if ·( bool ) stmt <br>stmt → if ·( bool ) stmt else stmt <br></div>")
	node23--> |"("| node32
	node24("<div>I24:<br>stmt → id ·= expr ; <br>loc → id ·<br></div>")
	node24--> |"="| node33
	node25("<div>I25:<br>loc → ·id <br>loc → ·loc [ num ] <br>stmt → ·break ; <br>stmt → ·do stmt while ( bool ) ; <br>stmt → ·while ( bool ) stmt <br>block → ·{ decls stmts } <br>stmt → ·if ( bool ) stmt else stmt <br>stmt → ·if ( bool ) stmt <br>stmt → ·loc = expr ; <br>stmt → ·id = expr ; <br>stmt → ·block <br>stmt → do ·stmt while ( bool ) ; <br></div>")
	node25--> |"id"| node24
	node25--> |"do"| node25
	node25--> |"stmt"| node34
	node25--> |"block"| node20
	node25--> |"break"| node19
	node25--> |"while"| node18
	node25--> |"if"| node23
	node25--> |"{"| node9
	node25--> |"loc"| node17
	node26("<div>I26:<br>type → type [ num ·] <br></div>")
	node26--> |"]"| node35
	node27("<div>I27:<br>decl → type id ; ·<br></div>")
	node28("<div>I28:<br>loc → ·id <br>loc → ·loc [ num ] <br>factor → ·false <br>factor → ·true <br>factor → ·real <br>factor → ·num <br>expr → ·expr - term <br>expr → ·expr + term <br>expr → ·term <br>term → ·term * unary <br>stmt → loc = ·expr ; <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·loc <br>factor → ·id <br></div>")
	node28--> |"true"| node46
	node28--> |"term"| node44
	node28--> |"unary"| node48
	node28--> |"-"| node43
	node28--> |"num"| node47
	node28--> |"("| node42
	node28--> |"!"| node41
	node28--> |"false"| node40
	node28--> |"real"| node39
	node28--> |"id"| node45
	node28--> |"factor"| node38
	node28--> |"loc"| node37
	node28--> |"expr"| node36
	node29("<div>I29:<br>loc → loc [ ·num ] <br></div>")
	node29--> |"num"| node49
	node30("<div>I30:<br>loc → ·id <br>loc → ·loc [ num ] <br>rel → ·expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <= expr <br>rel → ·expr < expr <br>equality → ·rel <br>equality → ·equality != rel <br>equality → ·equality == rel <br>join → ·join && equality <br>bool → ·join <br>bool → ·bool || join <br>join → ·equality <br>stmt → while ( ·bool ) stmt <br>unary → ·- unary <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·loc <br>factor → ·id <br>factor → ·num <br>factor → ·real <br>factor → ·true <br>factor → ·false <br></div>")
	node30--> |"unary"| node48
	node30--> |"num"| node47
	node30--> |"true"| node46
	node30--> |"rel"| node50
	node30--> |"term"| node44
	node30--> |"bool"| node51
	node30--> |"expr"| node52
	node30--> |"loc"| node37
	node30--> |"equality"| node53
	node30--> |"id"| node45
	node30--> |"factor"| node38
	node30--> |"real"| node39
	node30--> |"false"| node40
	node30--> |"!"| node41
	node30--> |"("| node42
	node30--> |"-"| node43
	node30--> |"join"| node54
	node31("<div>I31:<br>stmt → break ; ·<br></div>")
	node32("<div>I32:<br>loc → ·id <br>loc → ·loc [ num ] <br>factor → ·false <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <= expr <br>rel → ·expr < expr <br>equality → ·rel <br>equality → ·equality != rel <br>equality → ·equality == rel <br>join → ·equality <br>bool → ·bool || join <br>join → ·join && equality <br>stmt → if ( ·bool ) stmt else stmt <br>unary → ·! unary <br>bool → ·join <br>stmt → if ( ·bool ) stmt <br>term → ·unary <br>rel → ·expr <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·loc <br>factor → ·id <br>factor → ·num <br>factor → ·real <br>factor → ·true <br></div>")
	node32--> |"unary"| node48
	node32--> |"num"| node47
	node32--> |"true"| node46
	node32--> |"rel"| node50
	node32--> |"term"| node44
	node32--> |"bool"| node55
	node32--> |"expr"| node52
	node32--> |"loc"| node37
	node32--> |"equality"| node53
	node32--> |"id"| node45
	node32--> |"factor"| node38
	node32--> |"real"| node39
	node32--> |"false"| node40
	node32--> |"!"| node41
	node32--> |"("| node42
	node32--> |"-"| node43
	node32--> |"join"| node54
	node33("<div>I33:<br>loc → ·id <br>loc → ·loc [ num ] <br>factor → ·false <br>factor → ·true <br>factor → ·real <br>factor → ·num <br>unary → ·factor <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>factor → ·( expr ) <br>factor → ·loc <br>stmt → id = ·expr ; <br>factor → ·id <br></div>")
	node33--> |"true"| node46
	node33--> |"term"| node44
	node33--> |"unary"| node48
	node33--> |"-"| node43
	node33--> |"num"| node47
	node33--> |"("| node42
	node33--> |"!"| node41
	node33--> |"false"| node40
	node33--> |"real"| node39
	node33--> |"id"| node45
	node33--> |"factor"| node38
	node33--> |"loc"| node37
	node33--> |"expr"| node56
	node34("<div>I34:<br>stmt → do stmt ·while ( bool ) ; <br></div>")
	node34--> |"while"| node57
	node35("<div>I35:<br>type → type [ num ] ·<br></div>")
	node36("<div>I36:<br>stmt → loc = expr ·; <br>expr → expr ·+ term <br>expr → expr ·- term <br></div>")
	node36--> |";"| node60
	node36--> |"-"| node59
	node36--> |"+"| node58
	node37("<div>I37:<br>factor → loc ·<br>loc → loc ·[ num ] <br></div>")
	node37--> |"["| node29
	node38("<div>I38:<br>unary → factor ·<br></div>")
	node39("<div>I39:<br>factor → real ·<br></div>")
	node40("<div>I40:<br>factor → false ·<br></div>")
	node41("<div>I41:<br>factor → ·false <br>factor → ·true <br>loc → ·id <br>factor → ·real <br>loc → ·loc [ num ] <br>factor → ·num <br>factor → ·id <br>factor → ·loc <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>unary → ! ·unary <br></div>")
	node41--> |"true"| node46
	node41--> |"unary"| node61
	node41--> |"-"| node43
	node41--> |"num"| node47
	node41--> |"("| node42
	node41--> |"!"| node41
	node41--> |"false"| node40
	node41--> |"real"| node39
	node41--> |"id"| node45
	node41--> |"factor"| node38
	node41--> |"loc"| node37
	node42("<div>I42:<br>loc → ·id <br>loc → ·loc [ num ] <br>factor → ·false <br>factor → ·true <br>factor → ·real <br>factor → ·num <br>factor → ( ·expr ) <br>unary → ·- unary <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·loc <br>factor → ·id <br></div>")
	node42--> |"true"| node46
	node42--> |"term"| node44
	node42--> |"unary"| node48
	node42--> |"-"| node43
	node42--> |"num"| node47
	node42--> |"("| node42
	node42--> |"!"| node41
	node42--> |"false"| node40
	node42--> |"real"| node39
	node42--> |"id"| node45
	node42--> |"factor"| node38
	node42--> |"loc"| node37
	node42--> |"expr"| node62
	node43("<div>I43:<br>factor → ·false <br>factor → ·true <br>loc → ·id <br>factor → ·real <br>loc → ·loc [ num ] <br>factor → ·num <br>factor → ·id <br>factor → ·loc <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>factor → ·( expr ) <br>unary → - ·unary <br></div>")
	node43--> |"true"| node46
	node43--> |"unary"| node63
	node43--> |"-"| node43
	node43--> |"num"| node47
	node43--> |"("| node42
	node43--> |"!"| node41
	node43--> |"false"| node40
	node43--> |"real"| node39
	node43--> |"id"| node45
	node43--> |"factor"| node38
	node43--> |"loc"| node37
	node44("<div>I44:<br>term → term ·/ unary <br>term → term ·* unary <br>expr → term ·<br></div>")
	node44--> |"/"| node65
	node44--> |"*"| node64
	node45("<div>I45:<br>factor → id ·<br>loc → id ·<br></div>")
	node46("<div>I46:<br>factor → true ·<br></div>")
	node47("<div>I47:<br>factor → num ·<br></div>")
	node48("<div>I48:<br>term → unary ·<br></div>")
	node49("<div>I49:<br>loc → loc [ num ·] <br></div>")
	node49--> |"]"| node66
	node50("<div>I50:<br>equality → rel ·<br></div>")
	node51("<div>I51:<br>stmt → while ( bool ·) stmt <br>bool → bool ·|| join <br></div>")
	node51--> |")"| node68
	node51--> |"||"| node67
	node52("<div>I52:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr ·< expr <br>rel → expr ·<= expr <br>rel → expr ·>= expr <br>rel → expr ·> expr <br>rel → expr ·<br></div>")
	node52--> |"-"| node59
	node52--> |">="| node72
	node52--> |"+"| node58
	node52--> |"<"| node71
	node52--> |">"| node70
	node52--> |"<="| node69
	node53("<div>I53:<br>join → equality ·<br>equality → equality ·== rel <br>equality → equality ·!= rel <br></div>")
	node53--> |"=="| node74
	node53--> |"!="| node73
	node54("<div>I54:<br>bool → join ·<br>join → join ·&& equality <br></div>")
	node54--> |"&&"| node75
	node55("<div>I55:<br>stmt → if ( bool ·) stmt <br>stmt → if ( bool ·) stmt else stmt <br>bool → bool ·|| join <br></div>")
	node55--> |")"| node76
	node55--> |"||"| node67
	node56("<div>I56:<br>stmt → id = expr ·; <br>expr → expr ·- term <br>expr → expr ·+ term <br></div>")
	node56--> |";"| node77
	node56--> |"-"| node59
	node56--> |"+"| node58
	node57("<div>I57:<br>stmt → do stmt while ·( bool ) ; <br></div>")
	node57--> |"("| node78
	node58("<div>I58:<br>loc → ·id <br>loc → ·loc [ num ] <br>factor → ·false <br>expr → expr + ·term <br>term → ·term / unary <br>term → ·term * unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·loc <br>factor → ·id <br>factor → ·num <br>factor → ·real <br>factor → ·true <br></div>")
	node58--> |"true"| node46
	node58--> |"term"| node79
	node58--> |"unary"| node48
	node58--> |"-"| node43
	node58--> |"num"| node47
	node58--> |"("| node42
	node58--> |"!"| node41
	node58--> |"false"| node40
	node58--> |"real"| node39
	node58--> |"id"| node45
	node58--> |"factor"| node38
	node58--> |"loc"| node37
	node59("<div>I59:<br>loc → ·id <br>loc → ·loc [ num ] <br>factor → ·false <br>expr → expr - ·term <br>term → ·unary <br>term → ·term * unary <br>term → ·term / unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·loc <br>factor → ·id <br>factor → ·num <br>factor → ·real <br>factor → ·true <br></div>")
	node59--> |"true"| node46
	node59--> |"term"| node80
	node59--> |"unary"| node48
	node59--> |"-"| node43
	node59--> |"num"| node47
	node59--> |"("| node42
	node59--> |"!"| node41
	node59--> |"false"| node40
	node59--> |"real"| node39
	node59--> |"id"| node45
	node59--> |"factor"| node38
	node59--> |"loc"| node37
	node60("<div>I60:<br>stmt → loc = expr ; ·<br></div>")
	node61("<div>I61:<br>unary → ! unary ·<br></div>")
	node62("<div>I62:<br>expr → expr ·- term <br>expr → expr ·+ term <br>factor → ( expr ·) <br></div>")
	node62--> |")"| node81
	node62--> |"-"| node59
	node62--> |"+"| node58
	node63("<div>I63:<br>unary → - unary ·<br></div>")
	node64("<div>I64:<br>factor → ·false <br>factor → ·true <br>loc → ·id <br>factor → ·real <br>factor → ·id <br>factor → ·loc <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>loc → ·loc [ num ] <br>factor → ·num <br>term → term * ·unary <br></div>")
	node64--> |"true"| node46
	node64--> |"unary"| node82
	node64--> |"-"| node43
	node64--> |"num"| node47
	node64--> |"("| node42
	node64--> |"!"| node41
	node64--> |"false"| node40
	node64--> |"real"| node39
	node64--> |"id"| node45
	node64--> |"factor"| node38
	node64--> |"loc"| node37
	node65("<div>I65:<br>factor → ·false <br>factor → ·true <br>loc → ·loc [ num ] <br>factor → ·num <br>factor → ·id <br>factor → ·loc <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>loc → ·id <br>factor → ·real <br>term → term / ·unary <br></div>")
	node65--> |"true"| node46
	node65--> |"unary"| node83
	node65--> |"-"| node43
	node65--> |"num"| node47
	node65--> |"("| node42
	node65--> |"!"| node41
	node65--> |"false"| node40
	node65--> |"real"| node39
	node65--> |"id"| node45
	node65--> |"factor"| node38
	node65--> |"loc"| node37
	node66("<div>I66:<br>loc → loc [ num ] ·<br></div>")
	node67("<div>I67:<br>loc → ·id <br>loc → ·loc [ num ] <br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id <br>factor → ·loc <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>term → ·term * unary <br>expr → ·term <br>factor → ·real <br>bool → bool || ·join <br>rel → ·expr >= expr <br>join → ·join && equality <br>join → ·equality <br>equality → ·equality == rel <br>equality → ·equality != rel <br>equality → ·rel <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr <br>expr → ·expr + term <br>expr → ·expr - term <br></div>")
	node67--> |"unary"| node48
	node67--> |"num"| node47
	node67--> |"true"| node46
	node67--> |"rel"| node50
	node67--> |"term"| node44
	node67--> |"expr"| node52
	node67--> |"loc"| node37
	node67--> |"equality"| node53
	node67--> |"factor"| node38
	node67--> |"id"| node45
	node67--> |"real"| node39
	node67--> |"false"| node40
	node67--> |"!"| node41
	node67--> |"("| node42
	node67--> |"-"| node43
	node67--> |"join"| node84
	node68("<div>I68:<br>loc → ·loc [ num ] <br>stmt → ·block <br>stmt → ·break ; <br>stmt → ·do stmt while ( bool ) ; <br>stmt → ·while ( bool ) stmt <br>block → ·{ decls stmts } <br>stmt → ·if ( bool ) stmt else stmt <br>stmt → ·if ( bool ) stmt <br>stmt → ·loc = expr ; <br>stmt → ·id = expr ; <br>loc → ·id <br>stmt → while ( bool ) ·stmt <br></div>")
	node68--> |"id"| node24
	node68--> |"do"| node25
	node68--> |"stmt"| node85
	node68--> |"block"| node20
	node68--> |"break"| node19
	node68--> |"while"| node18
	node68--> |"if"| node23
	node68--> |"{"| node9
	node68--> |"loc"| node17
	node69("<div>I69:<br>loc → ·id <br>loc → ·loc [ num ] <br>factor → ·false <br>factor → ·true <br>factor → ·real <br>factor → ·num <br>rel → expr <= ·expr <br>term → ·unary <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·loc <br>factor → ·id <br></div>")
	node69--> |"true"| node46
	node69--> |"term"| node44
	node69--> |"unary"| node48
	node69--> |"-"| node43
	node69--> |"num"| node47
	node69--> |"("| node42
	node69--> |"!"| node41
	node69--> |"false"| node40
	node69--> |"real"| node39
	node69--> |"id"| node45
	node69--> |"factor"| node38
	node69--> |"loc"| node37
	node69--> |"expr"| node86
	node70("<div>I70:<br>loc → ·id <br>loc → ·loc [ num ] <br>factor → ·false <br>factor → ·true <br>factor → ·real <br>factor → ·num <br>rel → expr > ·expr <br>unary → ·- unary <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·loc <br>factor → ·id <br></div>")
	node70--> |"true"| node46
	node70--> |"term"| node44
	node70--> |"unary"| node48
	node70--> |"-"| node43
	node70--> |"num"| node47
	node70--> |"("| node42
	node70--> |"!"| node41
	node70--> |"false"| node40
	node70--> |"real"| node39
	node70--> |"id"| node45
	node70--> |"factor"| node38
	node70--> |"loc"| node37
	node70--> |"expr"| node87
	node71("<div>I71:<br>loc → ·id <br>loc → ·loc [ num ] <br>factor → ·false <br>factor → ·true <br>factor → ·real <br>factor → ·num <br>rel → expr < ·expr <br>term → ·term / unary <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·loc <br>factor → ·id <br></div>")
	node71--> |"true"| node46
	node71--> |"term"| node44
	node71--> |"unary"| node48
	node71--> |"-"| node43
	node71--> |"num"| node47
	node71--> |"("| node42
	node71--> |"!"| node41
	node71--> |"false"| node40
	node71--> |"real"| node39
	node71--> |"id"| node45
	node71--> |"factor"| node38
	node71--> |"loc"| node37
	node71--> |"expr"| node88
	node72("<div>I72:<br>loc → ·id <br>loc → ·loc [ num ] <br>factor → ·false <br>factor → ·true <br>factor → ·real <br>factor → ·num <br>rel → expr >= ·expr <br>unary → ·! unary <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·loc <br>factor → ·id <br></div>")
	node72--> |"true"| node46
	node72--> |"term"| node44
	node72--> |"unary"| node48
	node72--> |"-"| node43
	node72--> |"num"| node47
	node72--> |"("| node42
	node72--> |"!"| node41
	node72--> |"false"| node40
	node72--> |"real"| node39
	node72--> |"id"| node45
	node72--> |"factor"| node38
	node72--> |"loc"| node37
	node72--> |"expr"| node89
	node73("<div>I73:<br>loc → ·id <br>loc → ·loc [ num ] <br>factor → ·false <br>factor → ·true <br>factor → ·real <br>factor → ·num <br>factor → ·id <br>factor → ·loc <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>equality → equality != ·rel <br>rel → ·expr >= expr <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br></div>")
	node73--> |"unary"| node48
	node73--> |"rel"| node90
	node73--> |"term"| node44
	node73--> |"true"| node46
	node73--> |"expr"| node52
	node73--> |"loc"| node37
	node73--> |"factor"| node38
	node73--> |"id"| node45
	node73--> |"real"| node39
	node73--> |"false"| node40
	node73--> |"!"| node41
	node73--> |"("| node42
	node73--> |"num"| node47
	node73--> |"-"| node43
	node74("<div>I74:<br>loc → ·id <br>loc → ·loc [ num ] <br>factor → ·false <br>factor → ·true <br>factor → ·real <br>factor → ·num <br>factor → ·id <br>factor → ·loc <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>equality → equality == ·rel <br>rel → ·expr <= expr <br>rel → ·expr < expr <br>rel → ·expr >= expr <br>rel → ·expr > expr <br>rel → ·expr <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br></div>")
	node74--> |"unary"| node48
	node74--> |"rel"| node91
	node74--> |"term"| node44
	node74--> |"true"| node46
	node74--> |"expr"| node52
	node74--> |"loc"| node37
	node74--> |"factor"| node38
	node74--> |"id"| node45
	node74--> |"real"| node39
	node74--> |"false"| node40
	node74--> |"!"| node41
	node74--> |"("| node42
	node74--> |"num"| node47
	node74--> |"-"| node43
	node75("<div>I75:<br>loc → ·id <br>factor → ·true <br>factor → ·real <br>factor → ·num <br>factor → ·id <br>factor → ·loc <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>loc → ·loc [ num ] <br>factor → ·false <br>join → join && ·equality <br>rel → ·expr <br>equality → ·equality == rel <br>equality → ·equality != rel <br>equality → ·rel <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr >= expr <br>rel → ·expr > expr <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br></div>")
	node75--> |"unary"| node48
	node75--> |"num"| node47
	node75--> |"rel"| node50
	node75--> |"term"| node44
	node75--> |"true"| node46
	node75--> |"expr"| node52
	node75--> |"loc"| node37
	node75--> |"equality"| node92
	node75--> |"factor"| node38
	node75--> |"id"| node45
	node75--> |"real"| node39
	node75--> |"false"| node40
	node75--> |"!"| node41
	node75--> |"("| node42
	node75--> |"-"| node43
	node76("<div>I76:<br>loc → ·id <br>stmt → ·break ; <br>stmt → ·do stmt while ( bool ) ; <br>stmt → ·while ( bool ) stmt <br>block → ·{ decls stmts } <br>stmt → ·if ( bool ) stmt else stmt <br>stmt → ·if ( bool ) stmt <br>stmt → ·loc = expr ; <br>stmt → ·id = expr ; <br>loc → ·loc [ num ] <br>stmt → if ( bool ) ·stmt else stmt <br>stmt → ·block <br>stmt → if ( bool ) ·stmt <br></div>")
	node76--> |"id"| node24
	node76--> |"do"| node25
	node76--> |"stmt"| node93
	node76--> |"block"| node20
	node76--> |"break"| node19
	node76--> |"while"| node18
	node76--> |"if"| node23
	node76--> |"{"| node9
	node76--> |"loc"| node17
	node77("<div>I77:<br>stmt → id = expr ; ·<br></div>")
	node78("<div>I78:<br>loc → ·id <br>loc → ·loc [ num ] <br>rel → ·expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <= expr <br>rel → ·expr < expr <br>equality → ·rel <br>equality → ·equality != rel <br>equality → ·equality == rel <br>join → ·join && equality <br>bool → ·join <br>bool → ·bool || join <br>join → ·equality <br>stmt → do stmt while ( ·bool ) ; <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·loc <br>factor → ·id <br>factor → ·num <br>factor → ·real <br>factor → ·true <br>factor → ·false <br></div>")
	node78--> |"unary"| node48
	node78--> |"num"| node47
	node78--> |"true"| node46
	node78--> |"rel"| node50
	node78--> |"term"| node44
	node78--> |"bool"| node94
	node78--> |"expr"| node52
	node78--> |"loc"| node37
	node78--> |"equality"| node53
	node78--> |"id"| node45
	node78--> |"factor"| node38
	node78--> |"real"| node39
	node78--> |"false"| node40
	node78--> |"!"| node41
	node78--> |"("| node42
	node78--> |"-"| node43
	node78--> |"join"| node54
	node79("<div>I79:<br>term → term ·* unary <br>term → term ·/ unary <br>expr → expr + term ·<br></div>")
	node79--> |"/"| node65
	node79--> |"*"| node64
	node80("<div>I80:<br>term → term ·/ unary <br>term → term ·* unary <br>expr → expr - term ·<br></div>")
	node80--> |"/"| node65
	node80--> |"*"| node64
	node81("<div>I81:<br>factor → ( expr ) ·<br></div>")
	node82("<div>I82:<br>term → term * unary ·<br></div>")
	node83("<div>I83:<br>term → term / unary ·<br></div>")
	node84("<div>I84:<br>join → join ·&& equality <br>bool → bool || join ·<br></div>")
	node84--> |"&&"| node75
	node85("<div>I85:<br>stmt → while ( bool ) stmt ·<br></div>")
	node86("<div>I86:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr <= expr ·<br></div>")
	node86--> |"-"| node59
	node86--> |"+"| node58
	node87("<div>I87:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr > expr ·<br></div>")
	node87--> |"-"| node59
	node87--> |"+"| node58
	node88("<div>I88:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr < expr ·<br></div>")
	node88--> |"-"| node59
	node88--> |"+"| node58
	node89("<div>I89:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr >= expr ·<br></div>")
	node89--> |"-"| node59
	node89--> |"+"| node58
	node90("<div>I90:<br>equality → equality != rel ·<br></div>")
	node91("<div>I91:<br>equality → equality == rel ·<br></div>")
	node92("<div>I92:<br>equality → equality ·!= rel <br>equality → equality ·== rel <br>join → join && equality ·<br></div>")
	node92--> |"=="| node74
	node92--> |"!="| node73
	node93("<div>I93:<br>stmt → if ( bool ) stmt ·<br>stmt → if ( bool ) stmt ·else stmt <br></div>")
	node93--> |"else"| node95
	node94("<div>I94:<br>stmt → do stmt while ( bool ·) ; <br>bool → bool ·|| join <br></div>")
	node94--> |")"| node96
	node94--> |"||"| node67
	node95("<div>I95:<br>loc → ·id <br>loc → ·loc [ num ] <br>stmt → ·block <br>stmt → ·break ; <br>stmt → ·do stmt while ( bool ) ; <br>block → ·{ decls stmts } <br>stmt → ·if ( bool ) stmt else stmt <br>stmt → ·if ( bool ) stmt <br>stmt → ·loc = expr ; <br>stmt → ·id = expr ; <br>stmt → ·while ( bool ) stmt <br>stmt → if ( bool ) stmt else ·stmt <br></div>")
	node95--> |"id"| node24
	node95--> |"do"| node25
	node95--> |"stmt"| node97
	node95--> |"block"| node20
	node95--> |"break"| node19
	node95--> |"while"| node18
	node95--> |"if"| node23
	node95--> |"{"| node9
	node95--> |"loc"| node17
	node96("<div>I96:<br>stmt → do stmt while ( bool ) ·; <br></div>")
	node96--> |";"| node98
	node97("<div>I97:<br>stmt → if ( bool ) stmt else stmt ·<br></div>")
	node98("<div>I98:<br>stmt → do stmt while ( bool ) ; ·<br></div>")
```
