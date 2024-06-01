## 产生式

- S → program 
- program → basics id ( ) block 
- block → { declarations stmts } 
- declarations → declaration declarations 
- declarations → ε 
- declaration → basics id ; 
- declaration → array_declaration ; 
- basics → void 
- basics → int 
- basics → float 
- stmts → stmt stmts 
- stmts → ε 
- stmt → assignment 
- stmt → declaration 
- stmt → array_assignment 
- stmt → while_loop 
- stmt → if_stmt 
- stmt → break_stmt 
- assignment → id = expr ; 
- array_init → array_init , num 
- array_init → num 
- array_init → array_init , id 
- array_init → id 
- array_declaration → basics id [ num ] 
- array_declaration → basics id [ num ] = { array_init } 
- array_declaration → basics id [ id ] = { array_init } 
- array_assignment → id [ num ] = expr ; 
- array_assignment → id [ id ] = expr ; 
- while_loop → while ( bool ) stmt_or_block 
- stmt_or_block → stmt 
- stmt_or_block → block 
- if_stmt → if ( bool ) stmt_or_block block_tail 
- block_tail → ε 
- block_tail → else stmt_or_block 
- block_tail → else if ( bool ) stmt_or_block block_tail 
- bool → join 
- join → join && equality 
- join → equality 
- equality → equality == rel 
- equality → equality != rel 
- equality → rel 
- rel → expr < expr 
- rel → expr <= expr 
- rel → expr > expr 
- rel → expr >= expr 
- rel → expr 
- expr → { expr } 
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
- factor → id 
- factor → id [ num ] 
- factor → id [ id ] 
- factor → num 
- factor → true 
- factor → false 
- break_stmt → break ; 
- START → S 

## FA Graph

```mermaid
	graph LR
	node0("<div>I0:<br>basics → ·float <br>basics → ·int <br>basics → ·void <br>program → ·basics id ( ) block <br>S → ·program <br>START → ·S <br></div>")
	node0--> |"float"| node6
	node0--> |"program"| node4
	node0--> |"void"| node5
	node0--> |"int"| node3
	node0--> |"S"| node2
	node0--> |"basics"| node1
	node1("<div>I1:<br>program → basics ·id ( ) block <br></div>")
	node1--> |"id"| node7
	node2("<div>I2:<br>START → S ·<br></div>")
	node3("<div>I3:<br>basics → int ·<br></div>")
	node4("<div>I4:<br>S → program ·<br></div>")
	node5("<div>I5:<br>basics → void ·<br></div>")
	node6("<div>I6:<br>basics → float ·<br></div>")
	node7("<div>I7:<br>program → basics id ·( ) block <br></div>")
	node7--> |"("| node8
	node8("<div>I8:<br>program → basics id ( ·) block <br></div>")
	node8--> |")"| node9
	node9("<div>I9:<br>block → ·{ declarations stmts } <br>program → basics id ( ) ·block <br></div>")
	node9--> |"{"| node11
	node9--> |"block"| node10
	node10("<div>I10:<br>program → basics id ( ) block ·<br></div>")
	node11("<div>I11:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>declaration → ·basics id ; <br>declaration → ·array_declaration ; <br>declarations → ε ·<br>declarations → ·declaration declarations <br>block → { ·declarations stmts } <br></div>")
	node11--> |"array_declaration"| node15
	node11--> |"float"| node6
	node11--> |"declaration"| node14
	node11--> |"declarations"| node13
	node11--> |"void"| node5
	node11--> |"int"| node3
	node11--> |"basics"| node12
	node12("<div>I12:<br>declaration → basics ·id ; <br>array_declaration → basics ·id [ num ] <br>array_declaration → basics ·id [ num ] = { array_init } <br>array_declaration → basics ·id [ id ] = { array_init } <br></div>")
	node12--> |"id"| node16
	node13("<div>I13:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·int <br>basics → ·void <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ id ] = expr ; <br>block → { declarations ·stmts } <br>declaration → ·array_declaration ; <br>stmts → ·stmt stmts <br>basics → ·float <br>stmts → ε ·<br>stmt → ·assignment <br>stmt → ·declaration <br>array_assignment → ·id [ num ] = expr ; <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>stmt → ·if_stmt <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>break_stmt → ·break ; <br>declaration → ·basics id ; <br></div>")
	node13--> |"id"| node26
	node13--> |"while_loop"| node17
	node13--> |"stmts"| node18
	node13--> |"int"| node3
	node13--> |"if"| node28
	node13--> |"assignment"| node24
	node13--> |"void"| node5
	node13--> |"array_assignment"| node19
	node13--> |"declaration"| node25
	node13--> |"break_stmt"| node20
	node13--> |"basics"| node12
	node13--> |"break"| node21
	node13--> |"while"| node22
	node13--> |"array_declaration"| node15
	node13--> |"stmt"| node23
	node13--> |"if_stmt"| node27
	node13--> |"float"| node6
	node14("<div>I14:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>declaration → ·basics id ; <br>declaration → ·array_declaration ; <br>declarations → ε ·<br>declarations → ·declaration declarations <br>declarations → declaration ·declarations <br></div>")
	node14--> |"array_declaration"| node15
	node14--> |"float"| node6
	node14--> |"declaration"| node14
	node14--> |"declarations"| node29
	node14--> |"void"| node5
	node14--> |"int"| node3
	node14--> |"basics"| node12
	node15("<div>I15:<br>declaration → array_declaration ·; <br></div>")
	node15--> |";"| node30
	node16("<div>I16:<br>array_declaration → basics id ·[ id ] = { array_init } <br>array_declaration → basics id ·[ num ] = { array_init } <br>array_declaration → basics id ·[ num ] <br>declaration → basics id ·; <br></div>")
	node16--> |";"| node32
	node16--> |"["| node31
	node17("<div>I17:<br>stmt → while_loop ·<br></div>")
	node18("<div>I18:<br>block → { declarations stmts ·} <br></div>")
	node18--> |"}"| node33
	node19("<div>I19:<br>stmt → array_assignment ·<br></div>")
	node20("<div>I20:<br>stmt → break_stmt ·<br></div>")
	node21("<div>I21:<br>break_stmt → break ·; <br></div>")
	node21--> |";"| node34
	node22("<div>I22:<br>while_loop → while ·( bool ) stmt_or_block <br></div>")
	node22--> |"("| node35
	node23("<div>I23:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·void <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ id ] = expr ; <br>basics → ·int <br>stmts → stmt ·stmts <br>stmts → ·stmt stmts <br>basics → ·float <br>stmts → ε ·<br>stmt → ·assignment <br>stmt → ·declaration <br>array_assignment → ·id [ num ] = expr ; <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>stmt → ·if_stmt <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>break_stmt → ·break ; <br>declaration → ·basics id ; <br>declaration → ·array_declaration ; <br></div>")
	node23--> |"id"| node26
	node23--> |"while_loop"| node17
	node23--> |"stmts"| node36
	node23--> |"int"| node3
	node23--> |"if"| node28
	node23--> |"assignment"| node24
	node23--> |"void"| node5
	node23--> |"array_assignment"| node19
	node23--> |"declaration"| node25
	node23--> |"break_stmt"| node20
	node23--> |"basics"| node12
	node23--> |"break"| node21
	node23--> |"while"| node22
	node23--> |"array_declaration"| node15
	node23--> |"stmt"| node23
	node23--> |"if_stmt"| node27
	node23--> |"float"| node6
	node24("<div>I24:<br>stmt → assignment ·<br></div>")
	node25("<div>I25:<br>stmt → declaration ·<br></div>")
	node26("<div>I26:<br>assignment → id ·= expr ; <br>array_assignment → id ·[ num ] = expr ; <br>array_assignment → id ·[ id ] = expr ; <br></div>")
	node26--> |"="| node38
	node26--> |"["| node37
	node27("<div>I27:<br>stmt → if_stmt ·<br></div>")
	node28("<div>I28:<br>if_stmt → if ·( bool ) stmt_or_block block_tail <br></div>")
	node28--> |"("| node39
	node29("<div>I29:<br>declarations → declaration declarations ·<br></div>")
	node30("<div>I30:<br>declaration → array_declaration ; ·<br></div>")
	node31("<div>I31:<br>array_declaration → basics id [ ·num ] <br>array_declaration → basics id [ ·num ] = { array_init } <br>array_declaration → basics id [ ·id ] = { array_init } <br></div>")
	node31--> |"id"| node41
	node31--> |"num"| node40
	node32("<div>I32:<br>declaration → basics id ; ·<br></div>")
	node33("<div>I33:<br>block → { declarations stmts } ·<br></div>")
	node34("<div>I34:<br>break_stmt → break ; ·<br></div>")
	node35("<div>I35:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>term → ·unary <br>term → ·term / unary <br>term → ·term * unary <br>expr → ·term <br>expr → ·expr - term <br>expr → ·expr + term <br>unary → ·! unary <br>while_loop → while ( ·bool ) stmt_or_block <br>join → ·equality <br>bool → ·join <br>join → ·join && equality <br>equality → ·equality == rel <br>equality → ·equality != rel <br>equality → ·rel <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·{ expr } <br></div>")
	node35--> |"{"| node56
	node35--> |"expr"| node42
	node35--> |"term"| node55
	node35--> |"bool"| node43
	node35--> |"rel"| node44
	node35--> |"true"| node50
	node35--> |"equality"| node45
	node35--> |"unary"| node46
	node35--> |"-"| node51
	node35--> |"join"| node48
	node35--> |"false"| node47
	node35--> |"!"| node49
	node35--> |"("| node52
	node35--> |"num"| node53
	node35--> |"factor"| node57
	node35--> |"id"| node54
	node36("<div>I36:<br>stmts → stmt stmts ·<br></div>")
	node37("<div>I37:<br>array_assignment → id [ ·id ] = expr ; <br>array_assignment → id [ ·num ] = expr ; <br></div>")
	node37--> |"id"| node59
	node37--> |"num"| node58
	node38("<div>I38:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ num ] <br>expr → ·expr - term <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·term <br>term → ·term * unary <br>assignment → id = ·expr ; <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br></div>")
	node38--> |"{"| node56
	node38--> |"factor"| node57
	node38--> |"id"| node54
	node38--> |"term"| node55
	node38--> |"true"| node50
	node38--> |"num"| node53
	node38--> |"("| node52
	node38--> |"!"| node49
	node38--> |"false"| node47
	node38--> |"-"| node51
	node38--> |"unary"| node46
	node38--> |"expr"| node60
	node39("<div>I39:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ num ] <br>factor → ·id <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>term → ·term * unary <br>expr → ·term <br>expr → ·expr - term <br>expr → ·expr + term <br>factor → ·( expr ) <br>if_stmt → if ( ·bool ) stmt_or_block block_tail <br>equality → ·rel <br>bool → ·join <br>join → ·join && equality <br>join → ·equality <br>equality → ·equality == rel <br>equality → ·equality != rel <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·{ expr } <br></div>")
	node39--> |"{"| node56
	node39--> |"expr"| node42
	node39--> |"term"| node55
	node39--> |"bool"| node61
	node39--> |"rel"| node44
	node39--> |"true"| node50
	node39--> |"equality"| node45
	node39--> |"unary"| node46
	node39--> |"-"| node51
	node39--> |"join"| node48
	node39--> |"false"| node47
	node39--> |"!"| node49
	node39--> |"("| node52
	node39--> |"num"| node53
	node39--> |"factor"| node57
	node39--> |"id"| node54
	node40("<div>I40:<br>array_declaration → basics id [ num ·] = { array_init } <br>array_declaration → basics id [ num ·] <br></div>")
	node40--> |"]"| node62
	node41("<div>I41:<br>array_declaration → basics id [ id ·] = { array_init } <br></div>")
	node41--> |"]"| node63
	node42("<div>I42:<br>rel → expr ·<br>rel → expr ·>= expr <br>rel → expr ·> expr <br>rel → expr ·<= expr <br>rel → expr ·< expr <br>expr → expr ·+ term <br>expr → expr ·- term <br></div>")
	node42--> |">="| node69
	node42--> |">"| node68
	node42--> |"<="| node67
	node42--> |"-"| node66
	node42--> |"+"| node65
	node42--> |"<"| node64
	node43("<div>I43:<br>while_loop → while ( bool ·) stmt_or_block <br></div>")
	node43--> |")"| node70
	node44("<div>I44:<br>equality → rel ·<br></div>")
	node45("<div>I45:<br>equality → equality ·!= rel <br>equality → equality ·== rel <br>join → equality ·<br></div>")
	node45--> |"=="| node72
	node45--> |"!="| node71
	node46("<div>I46:<br>term → unary ·<br></div>")
	node47("<div>I47:<br>factor → false ·<br></div>")
	node48("<div>I48:<br>join → join ·&& equality <br>bool → join ·<br></div>")
	node48--> |"&&"| node73
	node49("<div>I49:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·- unary <br>unary → ·! unary <br>unary → ·factor <br>unary → ! ·unary <br></div>")
	node49--> |"factor"| node57
	node49--> |"id"| node54
	node49--> |"true"| node50
	node49--> |"num"| node53
	node49--> |"("| node52
	node49--> |"!"| node49
	node49--> |"false"| node47
	node49--> |"-"| node51
	node49--> |"unary"| node74
	node50("<div>I50:<br>factor → true ·<br></div>")
	node51("<div>I51:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>unary → - ·unary <br></div>")
	node51--> |"factor"| node57
	node51--> |"id"| node54
	node51--> |"true"| node50
	node51--> |"num"| node53
	node51--> |"("| node52
	node51--> |"!"| node49
	node51--> |"false"| node47
	node51--> |"-"| node51
	node51--> |"unary"| node75
	node52("<div>I52:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ num ] <br>factor → ( ·expr ) <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br></div>")
	node52--> |"{"| node56
	node52--> |"factor"| node57
	node52--> |"id"| node54
	node52--> |"term"| node55
	node52--> |"true"| node50
	node52--> |"num"| node53
	node52--> |"("| node52
	node52--> |"!"| node49
	node52--> |"false"| node47
	node52--> |"-"| node51
	node52--> |"unary"| node46
	node52--> |"expr"| node76
	node53("<div>I53:<br>factor → num ·<br></div>")
	node54("<div>I54:<br>factor → id ·<br>factor → id ·[ num ] <br>factor → id ·[ id ] <br></div>")
	node54--> |"["| node77
	node55("<div>I55:<br>expr → term ·<br>term → term ·* unary <br>term → term ·/ unary <br></div>")
	node55--> |"/"| node79
	node55--> |"*"| node78
	node56("<div>I56:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ num ] <br>expr → { ·expr } <br>factor → ·id <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br></div>")
	node56--> |"{"| node56
	node56--> |"factor"| node57
	node56--> |"id"| node54
	node56--> |"term"| node55
	node56--> |"true"| node50
	node56--> |"num"| node53
	node56--> |"("| node52
	node56--> |"!"| node49
	node56--> |"false"| node47
	node56--> |"-"| node51
	node56--> |"unary"| node46
	node56--> |"expr"| node80
	node57("<div>I57:<br>unary → factor ·<br></div>")
	node58("<div>I58:<br>array_assignment → id [ num ·] = expr ; <br></div>")
	node58--> |"]"| node81
	node59("<div>I59:<br>array_assignment → id [ id ·] = expr ; <br></div>")
	node59--> |"]"| node82
	node60("<div>I60:<br>assignment → id = expr ·; <br>expr → expr ·+ term <br>expr → expr ·- term <br></div>")
	node60--> |";"| node83
	node60--> |"-"| node66
	node60--> |"+"| node65
	node61("<div>I61:<br>if_stmt → if ( bool ·) stmt_or_block block_tail <br></div>")
	node61--> |")"| node84
	node62("<div>I62:<br>array_declaration → basics id [ num ] ·<br>array_declaration → basics id [ num ] ·= { array_init } <br></div>")
	node62--> |"="| node85
	node63("<div>I63:<br>array_declaration → basics id [ id ] ·= { array_init } <br></div>")
	node63--> |"="| node86
	node64("<div>I64:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ num ] <br>rel → expr < ·expr <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br></div>")
	node64--> |"{"| node56
	node64--> |"factor"| node57
	node64--> |"id"| node54
	node64--> |"term"| node55
	node64--> |"true"| node50
	node64--> |"num"| node53
	node64--> |"("| node52
	node64--> |"!"| node49
	node64--> |"false"| node47
	node64--> |"-"| node51
	node64--> |"unary"| node46
	node64--> |"expr"| node87
	node65("<div>I65:<br>factor → ·false <br>expr → expr + ·term <br>factor → ·( expr ) <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·id <br>factor → ·id [ num ] <br>factor → ·id [ id ] <br>factor → ·num <br>factor → ·true <br></div>")
	node65--> |"factor"| node57
	node65--> |"id"| node54
	node65--> |"term"| node88
	node65--> |"true"| node50
	node65--> |"num"| node53
	node65--> |"("| node52
	node65--> |"!"| node49
	node65--> |"false"| node47
	node65--> |"-"| node51
	node65--> |"unary"| node46
	node66("<div>I66:<br>factor → ·false <br>expr → expr - ·term <br>term → ·unary <br>term → ·term * unary <br>term → ·term / unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br>factor → ·id [ id ] <br>factor → ·num <br>factor → ·true <br></div>")
	node66--> |"factor"| node57
	node66--> |"id"| node54
	node66--> |"term"| node89
	node66--> |"true"| node50
	node66--> |"num"| node53
	node66--> |"("| node52
	node66--> |"!"| node49
	node66--> |"false"| node47
	node66--> |"-"| node51
	node66--> |"unary"| node46
	node67("<div>I67:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ num ] <br>rel → expr <= ·expr <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br></div>")
	node67--> |"{"| node56
	node67--> |"factor"| node57
	node67--> |"id"| node54
	node67--> |"term"| node55
	node67--> |"true"| node50
	node67--> |"num"| node53
	node67--> |"("| node52
	node67--> |"!"| node49
	node67--> |"false"| node47
	node67--> |"-"| node51
	node67--> |"unary"| node46
	node67--> |"expr"| node90
	node68("<div>I68:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ num ] <br>rel → expr > ·expr <br>expr → ·expr + term <br>expr → ·{ expr } <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br></div>")
	node68--> |"{"| node56
	node68--> |"factor"| node57
	node68--> |"id"| node54
	node68--> |"term"| node55
	node68--> |"true"| node50
	node68--> |"num"| node53
	node68--> |"("| node52
	node68--> |"!"| node49
	node68--> |"false"| node47
	node68--> |"-"| node51
	node68--> |"unary"| node46
	node68--> |"expr"| node91
	node69("<div>I69:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ num ] <br>rel → expr >= ·expr <br>unary → ·! unary <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br></div>")
	node69--> |"{"| node56
	node69--> |"factor"| node57
	node69--> |"id"| node54
	node69--> |"term"| node55
	node69--> |"true"| node50
	node69--> |"num"| node53
	node69--> |"("| node52
	node69--> |"!"| node49
	node69--> |"false"| node47
	node69--> |"-"| node51
	node69--> |"unary"| node46
	node69--> |"expr"| node92
	node70("<div>I70:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ id ] = expr ; <br>array_assignment → ·id [ num ] = expr ; <br>while_loop → while ( bool ) ·stmt_or_block <br>stmt_or_block → ·stmt <br>stmt → ·if_stmt <br>stmt_or_block → ·block <br>stmt → ·break_stmt <br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>block → ·{ declarations stmts } <br>assignment → ·id = expr ; <br>break_stmt → ·break ; <br>declaration → ·basics id ; <br>declaration → ·array_declaration ; <br></div>")
	node70--> |"{"| node11
	node70--> |"id"| node26
	node70--> |"if_stmt"| node27
	node70--> |"float"| node6
	node70--> |"block"| node93
	node70--> |"while_loop"| node17
	node70--> |"stmt_or_block"| node94
	node70--> |"basics"| node12
	node70--> |"break"| node21
	node70--> |"while"| node22
	node70--> |"int"| node3
	node70--> |"array_assignment"| node19
	node70--> |"declaration"| node25
	node70--> |"break_stmt"| node20
	node70--> |"void"| node5
	node70--> |"if"| node28
	node70--> |"assignment"| node24
	node70--> |"array_declaration"| node15
	node70--> |"stmt"| node95
	node71("<div>I71:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>equality → equality != ·rel <br>expr → ·expr - term <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br></div>")
	node71--> |"{"| node56
	node71--> |"factor"| node57
	node71--> |"id"| node54
	node71--> |"num"| node53
	node71--> |"("| node52
	node71--> |"!"| node49
	node71--> |"false"| node47
	node71--> |"-"| node51
	node71--> |"unary"| node46
	node71--> |"term"| node55
	node71--> |"true"| node50
	node71--> |"rel"| node96
	node71--> |"expr"| node42
	node72("<div>I72:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>equality → equality == ·rel <br>expr → ·expr + term <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·{ expr } <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br></div>")
	node72--> |"{"| node56
	node72--> |"factor"| node57
	node72--> |"id"| node54
	node72--> |"num"| node53
	node72--> |"("| node52
	node72--> |"!"| node49
	node72--> |"false"| node47
	node72--> |"-"| node51
	node72--> |"unary"| node46
	node72--> |"term"| node55
	node72--> |"true"| node50
	node72--> |"rel"| node97
	node72--> |"expr"| node42
	node73("<div>I73:<br>factor → ·false <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>term → ·term * unary <br>factor → ·true <br>join → join && ·equality <br>rel → ·expr <br>equality → ·equality == rel <br>equality → ·equality != rel <br>equality → ·rel <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br></div>")
	node73--> |"expr"| node42
	node73--> |"true"| node50
	node73--> |"rel"| node44
	node73--> |"term"| node55
	node73--> |"equality"| node98
	node73--> |"unary"| node46
	node73--> |"-"| node51
	node73--> |"false"| node47
	node73--> |"!"| node49
	node73--> |"("| node52
	node73--> |"num"| node53
	node73--> |"factor"| node57
	node73--> |"id"| node54
	node73--> |"{"| node56
	node74("<div>I74:<br>unary → ! unary ·<br></div>")
	node75("<div>I75:<br>unary → - unary ·<br></div>")
	node76("<div>I76:<br>expr → expr ·- term <br>expr → expr ·+ term <br>factor → ( expr ·) <br></div>")
	node76--> |")"| node99
	node76--> |"-"| node66
	node76--> |"+"| node65
	node77("<div>I77:<br>factor → id [ ·id ] <br>factor → id [ ·num ] <br></div>")
	node77--> |"id"| node101
	node77--> |"num"| node100
	node78("<div>I78:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·! unary <br>unary → ·- unary <br>term → term * ·unary <br></div>")
	node78--> |"factor"| node57
	node78--> |"id"| node54
	node78--> |"true"| node50
	node78--> |"num"| node53
	node78--> |"("| node52
	node78--> |"!"| node49
	node78--> |"false"| node47
	node78--> |"-"| node51
	node78--> |"unary"| node102
	node79("<div>I79:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·- unary <br>unary → ·! unary <br>unary → ·factor <br>term → term / ·unary <br></div>")
	node79--> |"factor"| node57
	node79--> |"id"| node54
	node79--> |"true"| node50
	node79--> |"num"| node53
	node79--> |"("| node52
	node79--> |"!"| node49
	node79--> |"false"| node47
	node79--> |"-"| node51
	node79--> |"unary"| node103
	node80("<div>I80:<br>expr → expr ·- term <br>expr → expr ·+ term <br>expr → { expr ·} <br></div>")
	node80--> |"}"| node104
	node80--> |"-"| node66
	node80--> |"+"| node65
	node81("<div>I81:<br>array_assignment → id [ num ] ·= expr ; <br></div>")
	node81--> |"="| node105
	node82("<div>I82:<br>array_assignment → id [ id ] ·= expr ; <br></div>")
	node82--> |"="| node106
	node83("<div>I83:<br>assignment → id = expr ; ·<br></div>")
	node84("<div>I84:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ id ] = expr ; <br>array_assignment → ·id [ num ] = expr ; <br>array_declaration → ·basics id [ num ] <br>if_stmt → if ( bool ) ·stmt_or_block block_tail <br>stmt_or_block → ·stmt <br>stmt → ·if_stmt <br>stmt_or_block → ·block <br>stmt → ·break_stmt <br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>block → ·{ declarations stmts } <br>assignment → ·id = expr ; <br>break_stmt → ·break ; <br>declaration → ·basics id ; <br>declaration → ·array_declaration ; <br></div>")
	node84--> |"{"| node11
	node84--> |"id"| node26
	node84--> |"if_stmt"| node27
	node84--> |"float"| node6
	node84--> |"block"| node93
	node84--> |"while_loop"| node17
	node84--> |"stmt_or_block"| node107
	node84--> |"basics"| node12
	node84--> |"break"| node21
	node84--> |"while"| node22
	node84--> |"int"| node3
	node84--> |"array_assignment"| node19
	node84--> |"declaration"| node25
	node84--> |"break_stmt"| node20
	node84--> |"void"| node5
	node84--> |"if"| node28
	node84--> |"assignment"| node24
	node84--> |"array_declaration"| node15
	node84--> |"stmt"| node95
	node85("<div>I85:<br>array_declaration → basics id [ num ] = ·{ array_init } <br></div>")
	node85--> |"{"| node108
	node86("<div>I86:<br>array_declaration → basics id [ id ] = ·{ array_init } <br></div>")
	node86--> |"{"| node109
	node87("<div>I87:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr < expr ·<br></div>")
	node87--> |"-"| node66
	node87--> |"+"| node65
	node88("<div>I88:<br>term → term ·/ unary <br>term → term ·* unary <br>expr → expr + term ·<br></div>")
	node88--> |"/"| node79
	node88--> |"*"| node78
	node89("<div>I89:<br>term → term ·/ unary <br>term → term ·* unary <br>expr → expr - term ·<br></div>")
	node89--> |"/"| node79
	node89--> |"*"| node78
	node90("<div>I90:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr <= expr ·<br></div>")
	node90--> |"-"| node66
	node90--> |"+"| node65
	node91("<div>I91:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr > expr ·<br></div>")
	node91--> |"-"| node66
	node91--> |"+"| node65
	node92("<div>I92:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr >= expr ·<br></div>")
	node92--> |"-"| node66
	node92--> |"+"| node65
	node93("<div>I93:<br>stmt_or_block → block ·<br></div>")
	node94("<div>I94:<br>while_loop → while ( bool ) stmt_or_block ·<br></div>")
	node95("<div>I95:<br>stmt_or_block → stmt ·<br></div>")
	node96("<div>I96:<br>equality → equality != rel ·<br></div>")
	node97("<div>I97:<br>equality → equality == rel ·<br></div>")
	node98("<div>I98:<br>equality → equality ·!= rel <br>equality → equality ·== rel <br>join → join && equality ·<br></div>")
	node98--> |"=="| node72
	node98--> |"!="| node71
	node99("<div>I99:<br>factor → ( expr ) ·<br></div>")
	node100("<div>I100:<br>factor → id [ num ·] <br></div>")
	node100--> |"]"| node110
	node101("<div>I101:<br>factor → id [ id ·] <br></div>")
	node101--> |"]"| node111
	node102("<div>I102:<br>term → term * unary ·<br></div>")
	node103("<div>I103:<br>term → term / unary ·<br></div>")
	node104("<div>I104:<br>expr → { expr } ·<br></div>")
	node105("<div>I105:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ num ] <br>array_assignment → id [ num ] = ·expr ; <br>unary → ·factor <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>factor → ·( expr ) <br>factor → ·id <br></div>")
	node105--> |"{"| node56
	node105--> |"factor"| node57
	node105--> |"id"| node54
	node105--> |"term"| node55
	node105--> |"true"| node50
	node105--> |"num"| node53
	node105--> |"("| node52
	node105--> |"!"| node49
	node105--> |"false"| node47
	node105--> |"-"| node51
	node105--> |"unary"| node46
	node105--> |"expr"| node112
	node106("<div>I106:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ num ] <br>factor → ·( expr ) <br>array_assignment → id [ id ] = ·expr ; <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·id <br></div>")
	node106--> |"{"| node56
	node106--> |"factor"| node57
	node106--> |"id"| node54
	node106--> |"term"| node55
	node106--> |"true"| node50
	node106--> |"num"| node53
	node106--> |"("| node52
	node106--> |"!"| node49
	node106--> |"false"| node47
	node106--> |"-"| node51
	node106--> |"unary"| node46
	node106--> |"expr"| node113
	node107("<div>I107:<br>block_tail → ·else stmt_or_block <br>block_tail → ·else if ( bool ) stmt_or_block block_tail <br>block_tail → ε ·<br>if_stmt → if ( bool ) stmt_or_block ·block_tail <br></div>")
	node107--> |"else"| node115
	node107--> |"block_tail"| node114
	node108("<div>I108:<br>array_init → ·array_init , id <br>array_init → ·num <br>array_init → ·array_init , num <br>array_init → ·id <br>array_declaration → basics id [ num ] = { ·array_init } <br></div>")
	node108--> |"id"| node118
	node108--> |"num"| node117
	node108--> |"array_init"| node116
	node109("<div>I109:<br>array_init → ·id <br>array_init → ·array_init , id <br>array_init → ·num <br>array_init → ·array_init , num <br>array_declaration → basics id [ id ] = { ·array_init } <br></div>")
	node109--> |"id"| node118
	node109--> |"num"| node117
	node109--> |"array_init"| node119
	node110("<div>I110:<br>factor → id [ num ] ·<br></div>")
	node111("<div>I111:<br>factor → id [ id ] ·<br></div>")
	node112("<div>I112:<br>expr → expr ·- term <br>expr → expr ·+ term <br>array_assignment → id [ num ] = expr ·; <br></div>")
	node112--> |";"| node120
	node112--> |"-"| node66
	node112--> |"+"| node65
	node113("<div>I113:<br>expr → expr ·- term <br>expr → expr ·+ term <br>array_assignment → id [ id ] = expr ·; <br></div>")
	node113--> |";"| node121
	node113--> |"-"| node66
	node113--> |"+"| node65
	node114("<div>I114:<br>if_stmt → if ( bool ) stmt_or_block block_tail ·<br></div>")
	node115("<div>I115:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ id ] = expr ; <br>array_assignment → ·id [ num ] = expr ; <br>declaration → ·array_declaration ; <br>block_tail → else ·stmt_or_block <br>block_tail → else ·if ( bool ) stmt_or_block block_tail <br>stmt_or_block → ·stmt <br>stmt → ·if_stmt <br>stmt_or_block → ·block <br>stmt → ·break_stmt <br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>block → ·{ declarations stmts } <br>assignment → ·id = expr ; <br>break_stmt → ·break ; <br>declaration → ·basics id ; <br></div>")
	node115--> |"{"| node11
	node115--> |"id"| node26
	node115--> |"if_stmt"| node27
	node115--> |"float"| node6
	node115--> |"block"| node93
	node115--> |"while_loop"| node17
	node115--> |"stmt_or_block"| node122
	node115--> |"basics"| node12
	node115--> |"break"| node21
	node115--> |"while"| node22
	node115--> |"int"| node3
	node115--> |"array_assignment"| node19
	node115--> |"declaration"| node25
	node115--> |"break_stmt"| node20
	node115--> |"void"| node5
	node115--> |"if"| node123
	node115--> |"assignment"| node24
	node115--> |"array_declaration"| node15
	node115--> |"stmt"| node95
	node116("<div>I116:<br>array_declaration → basics id [ num ] = { array_init ·} <br>array_init → array_init ·, num <br>array_init → array_init ·, id <br></div>")
	node116--> |"}"| node125
	node116--> |","| node124
	node117("<div>I117:<br>array_init → num ·<br></div>")
	node118("<div>I118:<br>array_init → id ·<br></div>")
	node119("<div>I119:<br>array_declaration → basics id [ id ] = { array_init ·} <br>array_init → array_init ·, num <br>array_init → array_init ·, id <br></div>")
	node119--> |"}"| node126
	node119--> |","| node124
	node120("<div>I120:<br>array_assignment → id [ num ] = expr ; ·<br></div>")
	node121("<div>I121:<br>array_assignment → id [ id ] = expr ; ·<br></div>")
	node122("<div>I122:<br>block_tail → else stmt_or_block ·<br></div>")
	node123("<div>I123:<br>if_stmt → if ·( bool ) stmt_or_block block_tail <br>block_tail → else if ·( bool ) stmt_or_block block_tail <br></div>")
	node123--> |"("| node127
	node124("<div>I124:<br>array_init → array_init , ·id <br>array_init → array_init , ·num <br></div>")
	node124--> |"id"| node129
	node124--> |"num"| node128
	node125("<div>I125:<br>array_declaration → basics id [ num ] = { array_init } ·<br></div>")
	node126("<div>I126:<br>array_declaration → basics id [ id ] = { array_init } ·<br></div>")
	node127("<div>I127:<br>factor → ·false <br>rel → ·expr <br>rel → ·expr >= expr <br>rel → ·expr > expr <br>rel → ·expr <= expr <br>rel → ·expr < expr <br>equality → ·equality != rel <br>equality → ·equality == rel <br>join → ·equality <br>bool → ·join <br>join → ·join && equality <br>block_tail → else if ( ·bool ) stmt_or_block block_tail <br>equality → ·rel <br>if_stmt → if ( ·bool ) stmt_or_block block_tail <br>factor → ·( expr ) <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·id <br>factor → ·id [ num ] <br>factor → ·id [ id ] <br>factor → ·num <br>factor → ·true <br></div>")
	node127--> |"{"| node56
	node127--> |"expr"| node42
	node127--> |"term"| node55
	node127--> |"bool"| node130
	node127--> |"rel"| node44
	node127--> |"true"| node50
	node127--> |"equality"| node45
	node127--> |"unary"| node46
	node127--> |"-"| node51
	node127--> |"join"| node48
	node127--> |"false"| node47
	node127--> |"!"| node49
	node127--> |"("| node52
	node127--> |"num"| node53
	node127--> |"factor"| node57
	node127--> |"id"| node54
	node128("<div>I128:<br>array_init → array_init , num ·<br></div>")
	node129("<div>I129:<br>array_init → array_init , id ·<br></div>")
	node130("<div>I130:<br>if_stmt → if ( bool ·) stmt_or_block block_tail <br>block_tail → else if ( bool ·) stmt_or_block block_tail <br></div>")
	node130--> |")"| node131
	node131("<div>I131:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ id ] = expr ; <br>array_assignment → ·id [ num ] = expr ; <br>declaration → ·array_declaration ; <br>array_declaration → ·basics id [ num ] <br>if_stmt → if ( bool ) ·stmt_or_block block_tail <br>block_tail → else if ( bool ) ·stmt_or_block block_tail <br>stmt → ·array_assignment <br>stmt_or_block → ·stmt <br>stmt → ·if_stmt <br>stmt_or_block → ·block <br>stmt → ·break_stmt <br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·while_loop <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>block → ·{ declarations stmts } <br>assignment → ·id = expr ; <br>break_stmt → ·break ; <br>declaration → ·basics id ; <br></div>")
	node131--> |"{"| node11
	node131--> |"id"| node26
	node131--> |"if_stmt"| node27
	node131--> |"float"| node6
	node131--> |"block"| node93
	node131--> |"while_loop"| node17
	node131--> |"stmt_or_block"| node132
	node131--> |"basics"| node12
	node131--> |"break"| node21
	node131--> |"while"| node22
	node131--> |"int"| node3
	node131--> |"array_assignment"| node19
	node131--> |"declaration"| node25
	node131--> |"break_stmt"| node20
	node131--> |"void"| node5
	node131--> |"if"| node28
	node131--> |"assignment"| node24
	node131--> |"array_declaration"| node15
	node131--> |"stmt"| node95
	node132("<div>I132:<br>block_tail → ·else stmt_or_block <br>block_tail → else if ( bool ) stmt_or_block ·block_tail <br>block_tail → ·else if ( bool ) stmt_or_block block_tail <br>block_tail → ε ·<br>if_stmt → if ( bool ) stmt_or_block ·block_tail <br></div>")
	node132--> |"else"| node115
	node132--> |"block_tail"| node133
	node133("<div>I133:<br>if_stmt → if ( bool ) stmt_or_block block_tail ·<br>block_tail → else if ( bool ) stmt_or_block block_tail ·<br></div>")
```
