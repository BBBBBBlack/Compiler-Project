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
- assignment → id = ; 
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
	node8("<div>I8:<br>block → ·{ declarations stmts } <br>program → basics id ( ·) block <br>block → ·{ declarations stmts <br>program → basics id ( ·block <br></div>")
	node8--> |"{"| node11
	node8--> |")"| node10
	node8--> |"block"| node9
	node9("<div>I9:<br>program → basics id ( block ·<br></div>")
	node10("<div>I10:<br>block → ·{ declarations stmts <br>block → ·{ declarations stmts } <br>program → basics id ( ) ·block <br></div>")
	node10--> |"{"| node11
	node10--> |"block"| node12
	node11("<div>I11:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>declaration → ·array_declaration ; <br>declaration → ·basics id ; <br>declarations → ε ·<br>declarations → ·declaration declarations <br>block → { ·declarations stmts <br>array_declaration → ·basics id [ num ] = { array_init } <br>block → { ·declarations stmts } <br></div>")
	node11--> |"int"| node6
	node11--> |"void"| node5
	node11--> |"array_declaration"| node16
	node11--> |"float"| node4
	node11--> |"declarations"| node15
	node11--> |"declaration"| node14
	node11--> |"basics"| node13
	node12("<div>I12:<br>program → basics id ( ) block ·<br></div>")
	node13("<div>I13:<br>array_declaration → basics ·id [ num ] = { array_init } <br>declaration → basics ·id ; <br>array_declaration → basics ·id [ num ] <br>array_declaration → basics ·id [ id ] = { array_init } <br></div>")
	node13--> |"id"| node17
	node14("<div>I14:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>declaration → ·array_declaration ; <br>declarations → ε ·<br>declarations → ·declaration declarations <br>declaration → ·basics id ; <br>declarations → declaration ·declarations <br></div>")
	node14--> |"int"| node6
	node14--> |"void"| node5
	node14--> |"array_declaration"| node16
	node14--> |"float"| node4
	node14--> |"declarations"| node18
	node14--> |"declaration"| node14
	node14--> |"basics"| node13
	node15("<div>I15:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool stmt_or_block <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ id ] = expr ; <br>declaration → ·array_declaration ; <br>array_assignment → ·id [ num ] = expr ; <br>block → { declarations ·stmts <br>assignment → ·id = expr ; <br>if_stmt → ·if ( bool stmt_or_block block_tail <br>block → { declarations ·stmts } <br>declaration → ·basics id ; <br>stmts → ·stmt stmts <br>stmts → ε ·<br>stmt → ·declaration <br>break_stmt → ·break ; <br>stmt → ·assignment <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>stmt → ·if_stmt <br>stmt → ·break_stmt <br>assignment → ·id = ; <br></div>")
	node15--> |"while"| node28
	node15--> |"if"| node29
	node15--> |"assignment"| node19
	node15--> |"int"| node6
	node15--> |"basics"| node13
	node15--> |"if_stmt"| node20
	node15--> |"float"| node4
	node15--> |"stmts"| node26
	node15--> |"while_loop"| node22
	node15--> |"array_assignment"| node30
	node15--> |"void"| node5
	node15--> |"declaration"| node21
	node15--> |"break_stmt"| node23
	node15--> |"id"| node27
	node15--> |"array_declaration"| node16
	node15--> |"stmt"| node24
	node15--> |"break"| node25
	node16("<div>I16:<br>declaration → array_declaration ·; <br></div>")
	node16--> |";"| node31
	node17("<div>I17:<br>array_declaration → basics id ·[ id ] = { array_init } <br>array_declaration → basics id ·[ num ] <br>declaration → basics id ·; <br>array_declaration → basics id ·[ num ] = { array_init } <br></div>")
	node17--> |";"| node33
	node17--> |"["| node32
	node18("<div>I18:<br>declarations → declaration declarations ·<br></div>")
	node19("<div>I19:<br>stmt → assignment ·<br></div>")
	node20("<div>I20:<br>stmt → if_stmt ·<br></div>")
	node21("<div>I21:<br>stmt → declaration ·<br></div>")
	node22("<div>I22:<br>stmt → while_loop ·<br></div>")
	node23("<div>I23:<br>stmt → break_stmt ·<br></div>")
	node24("<div>I24:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool stmt_or_block <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ id ] = expr ; <br>array_assignment → ·id [ num ] = expr ; <br>break_stmt → ·break ; <br>stmts → stmt ·stmts <br>stmt → ·assignment <br>stmts → ·stmt stmts <br>stmts → ε ·<br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>stmt → ·if_stmt <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>if_stmt → ·if ( bool stmt_or_block block_tail <br>declaration → ·basics id ; <br>assignment → ·id = ; <br>declaration → ·array_declaration ; <br></div>")
	node24--> |"while"| node28
	node24--> |"if"| node29
	node24--> |"assignment"| node19
	node24--> |"int"| node6
	node24--> |"basics"| node13
	node24--> |"if_stmt"| node20
	node24--> |"float"| node4
	node24--> |"stmts"| node34
	node24--> |"while_loop"| node22
	node24--> |"array_assignment"| node30
	node24--> |"void"| node5
	node24--> |"declaration"| node21
	node24--> |"break_stmt"| node23
	node24--> |"id"| node27
	node24--> |"array_declaration"| node16
	node24--> |"stmt"| node24
	node24--> |"break"| node25
	node25("<div>I25:<br>break_stmt → break ·; <br></div>")
	node25--> |";"| node35
	node26("<div>I26:<br>block → { declarations stmts ·} <br>block → { declarations stmts ·<br></div>")
	node26--> |"}"| node36
	node27("<div>I27:<br>assignment → id ·= ; <br>assignment → id ·= expr ; <br>array_assignment → id ·[ num ] = expr ; <br>array_assignment → id ·[ id ] = expr ; <br></div>")
	node27--> |"["| node38
	node27--> |"="| node37
	node28("<div>I28:<br>while_loop → while ·( bool ) stmt_or_block <br>while_loop → while ·( bool stmt_or_block <br></div>")
	node28--> |"("| node39
	node29("<div>I29:<br>if_stmt → if ·( bool stmt_or_block block_tail <br>if_stmt → if ·( bool ) stmt_or_block block_tail <br></div>")
	node29--> |"("| node40
	node30("<div>I30:<br>stmt → array_assignment ·<br></div>")
	node31("<div>I31:<br>declaration → array_declaration ; ·<br></div>")
	node32("<div>I32:<br>array_declaration → basics id [ ·num ] = { array_init } <br>array_declaration → basics id [ ·num ] <br>array_declaration → basics id [ ·id ] = { array_init } <br></div>")
	node32--> |"num"| node42
	node32--> |"id"| node41
	node33("<div>I33:<br>declaration → basics id ; ·<br></div>")
	node34("<div>I34:<br>stmts → stmt stmts ·<br></div>")
	node35("<div>I35:<br>break_stmt → break ; ·<br></div>")
	node36("<div>I36:<br>block → { declarations stmts } ·<br></div>")
	node37("<div>I37:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr <br>assignment → id = ·; <br>term → ·term * unary <br>assignment → id = ·expr ; <br>expr → ·term <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br></div>")
	node37--> |";"| node55
	node37--> |"{"| node54
	node37--> |"term"| node52
	node37--> |"true"| node50
	node37--> |"id"| node51
	node37--> |"factor"| node49
	node37--> |"false"| node48
	node37--> |"num"| node53
	node37--> |"!"| node47
	node37--> |"("| node46
	node37--> |"-"| node45
	node37--> |"unary"| node44
	node37--> |"expr"| node43
	node38("<div>I38:<br>array_assignment → id [ ·id ] = expr ; <br>array_assignment → id [ ·num ] = expr ; <br></div>")
	node38--> |"num"| node57
	node38--> |"id"| node56
	node39("<div>I39:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>rel → ·expr <br>rel → ·expr >= expr <br>rel → ·expr <= expr <br>rel → ·expr < expr <br>equality → ·rel <br>equality → ·equality != rel <br>equality → ·equality == rel <br>join → ·equality <br>join → ·join && equality <br>bool → ·join <br>rel → ·expr > expr <br>while_loop → while ( ·bool stmt_or_block <br>factor → ·id [ num ] <br>while_loop → while ( ·bool ) stmt_or_block <br>term → ·term * unary <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·( expr <br>factor → ·id <br>factor → ·id [ num <br>factor → ·id [ id ] <br></div>")
	node39--> |"{"| node54
	node39--> |"num"| node53
	node39--> |"expr"| node58
	node39--> |"equality"| node60
	node39--> |"unary"| node44
	node39--> |"-"| node45
	node39--> |"join"| node61
	node39--> |"term"| node52
	node39--> |"bool"| node59
	node39--> |"rel"| node62
	node39--> |"true"| node50
	node39--> |"("| node46
	node39--> |"!"| node47
	node39--> |"false"| node48
	node39--> |"factor"| node49
	node39--> |"id"| node51
	node40("<div>I40:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>rel → ·expr <br>rel → ·expr >= expr <br>rel → ·expr > expr <br>rel → ·expr <= expr <br>rel → ·expr < expr <br>equality → ·rel <br>equality → ·equality == rel <br>join → ·equality <br>join → ·join && equality <br>bool → ·join <br>if_stmt → if ( ·bool ) stmt_or_block block_tail <br>equality → ·equality != rel <br>if_stmt → if ( ·bool stmt_or_block block_tail <br>unary → ·factor <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>factor → ·( expr ) <br>factor → ·( expr <br>factor → ·id <br>factor → ·id [ num ] <br>factor → ·id [ num <br>factor → ·id [ id ] <br></div>")
	node40--> |"{"| node54
	node40--> |"num"| node53
	node40--> |"expr"| node58
	node40--> |"equality"| node60
	node40--> |"unary"| node44
	node40--> |"-"| node45
	node40--> |"join"| node61
	node40--> |"term"| node52
	node40--> |"bool"| node63
	node40--> |"rel"| node62
	node40--> |"true"| node50
	node40--> |"("| node46
	node40--> |"!"| node47
	node40--> |"false"| node48
	node40--> |"factor"| node49
	node40--> |"id"| node51
	node41("<div>I41:<br>array_declaration → basics id [ id ·] = { array_init } <br></div>")
	node41--> |"]"| node64
	node42("<div>I42:<br>array_declaration → basics id [ num ·] <br>array_declaration → basics id [ num ·] = { array_init } <br></div>")
	node42--> |"]"| node65
	node43("<div>I43:<br>expr → expr ·- term <br>expr → expr ·+ term <br>assignment → id = expr ·; <br></div>")
	node43--> |";"| node68
	node43--> |"-"| node67
	node43--> |"+"| node66
	node44("<div>I44:<br>term → unary ·<br></div>")
	node45("<div>I45:<br>factor → ·false <br>unary → - ·unary <br>factor → ·( expr ) <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr <br>factor → ·id <br>factor → ·id [ num ] <br>factor → ·id [ num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·num <br>factor → ·true <br></div>")
	node45--> |"true"| node50
	node45--> |"id"| node51
	node45--> |"factor"| node49
	node45--> |"false"| node48
	node45--> |"num"| node53
	node45--> |"!"| node47
	node45--> |"("| node46
	node45--> |"-"| node45
	node45--> |"unary"| node69
	node46("<div>I46:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr <br>factor → ( ·expr <br>unary → ·factor <br>factor → ( ·expr ) <br>unary → ·- unary <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>factor → ·( expr ) <br></div>")
	node46--> |"{"| node54
	node46--> |"term"| node52
	node46--> |"true"| node50
	node46--> |"id"| node51
	node46--> |"factor"| node49
	node46--> |"false"| node48
	node46--> |"num"| node53
	node46--> |"!"| node47
	node46--> |"("| node46
	node46--> |"-"| node45
	node46--> |"unary"| node44
	node46--> |"expr"| node70
	node47("<div>I47:<br>factor → ·false <br>unary → ! ·unary <br>factor → ·true <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·( expr <br>factor → ·id <br>factor → ·id [ num ] <br>factor → ·id [ num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·num <br></div>")
	node47--> |"true"| node50
	node47--> |"id"| node51
	node47--> |"factor"| node49
	node47--> |"false"| node48
	node47--> |"num"| node53
	node47--> |"!"| node47
	node47--> |"("| node46
	node47--> |"-"| node45
	node47--> |"unary"| node71
	node48("<div>I48:<br>factor → false ·<br></div>")
	node49("<div>I49:<br>unary → factor ·<br></div>")
	node50("<div>I50:<br>factor → true ·<br></div>")
	node51("<div>I51:<br>factor → id ·<br>factor → id ·[ num ] <br>factor → id ·[ num <br>factor → id ·[ id ] <br>factor → id ·[ id ] <br></div>")
	node51--> |"["| node72
	node52("<div>I52:<br>term → term ·/ unary <br>expr → term ·<br>term → term ·* unary <br></div>")
	node52--> |"*"| node74
	node52--> |"/"| node73
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
	node66--> |"!"| node47
	node66--> |"("| node46
	node66--> |"-"| node45
	node66--> |"unary"| node44
	node67("<div>I67:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>expr → expr - ·term <br>factor → ·( expr <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br>factor → ·id [ num <br>factor → ·id [ id ] <br></div>")
	node67--> |"term"| node94
	node67--> |"true"| node50
	node67--> |"id"| node51
	node67--> |"factor"| node49
	node67--> |"false"| node48
	node67--> |"num"| node53
	node67--> |"!"| node47
	node67--> |"("| node46
	node67--> |"-"| node45
	node67--> |"unary"| node44
	node68("<div>I68:<br>assignment → id = expr ; ·<br></div>")
	node69("<div>I69:<br>unary → - unary ·<br></div>")
	node70("<div>I70:<br>expr → expr ·- term <br>expr → expr ·+ term <br>factor → ( expr ·) <br>factor → ( expr ·<br></div>")
	node70--> |")"| node95
	node70--> |"-"| node67
	node70--> |"+"| node66
	node71("<div>I71:<br>unary → ! unary ·<br></div>")
	node72("<div>I72:<br>factor → id [ ·id ] <br>factor → id [ ·id ] <br>factor → id [ ·num <br>factor → id [ ·num ] <br></div>")
	node72--> |"num"| node97
	node72--> |"id"| node96
	node73("<div>I73:<br>factor → ·false <br>term → term / ·unary <br>unary → ·factor <br>unary → ·! unary <br>unary → ·- unary <br>factor → ·( expr ) <br>factor → ·( expr <br>factor → ·id <br>factor → ·id [ num ] <br>factor → ·id [ num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·num <br>factor → ·true <br></div>")
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
	node73--> |"!"| node47
	node73--> |"("| node46
	node73--> |"-"| node45
	node73--> |"unary"| node98
	node74("<div>I74:<br>factor → ·false <br>term → term * ·unary <br>unary → ·- unary <br>unary → ·! unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·( expr <br>factor → ·id <br>factor → ·id [ num ] <br>factor → ·id [ num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·num <br>factor → ·true <br></div>")
	node74--> |"true"| node50
	node74--> |"id"| node51
	node74--> |"factor"| node49
	node74--> |"false"| node48
	node74--> |"num"| node53
	node74--> |"!"| node47
	node74--> |"("| node46
	node74--> |"-"| node45
	node74--> |"unary"| node99
	node75("<div>I75:<br>expr → expr ·+ term <br>expr → expr ·- term <br>expr → { expr ·} <br></div>")
	node75--> |"}"| node100
	node75--> |"-"| node67
	node75--> |"+"| node66
	node76("<div>I76:<br>array_assignment → id [ id ] ·= expr ; <br></div>")
	node76--> |"="| node101
	node77("<div>I77:<br>array_assignment → id [ num ] ·= expr ; <br></div>")
	node77--> |"="| node102
	node78("<div>I78:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>rel → expr < ·expr <br>term → ·term * unary <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·( expr <br></div>")
	node78--> |"{"| node54
	node78--> |"term"| node52
	node78--> |"true"| node50
	node78--> |"num"| node53
	node78--> |"!"| node47
	node78--> |"("| node46
	node78--> |"-"| node45
	node78--> |"unary"| node44
	node78--> |"expr"| node103
	node79("<div>I79:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>rel → expr <= ·expr <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·( expr <br></div>")
	node79--> |"{"| node54
	node79--> |"term"| node52
	node79--> |"true"| node50
	node79--> |"num"| node53
	node79--> |"!"| node47
	node79--> |"("| node46
	node79--> |"-"| node45
	node79--> |"unary"| node44
	node79--> |"expr"| node104
	node80("<div>I80:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>rel → expr > ·expr <br>expr → ·expr + term <br>expr → ·{ expr } <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·( expr <br></div>")
	node80--> |"{"| node54
	node80--> |"term"| node52
	node80--> |"true"| node50
	node80--> |"id"| node51
	node80--> |"factor"| node49
	node80--> |"false"| node48
	node80--> |"num"| node53
	node80--> |"!"| node47
	node80--> |"("| node46
	node80--> |"-"| node45
	node80--> |"unary"| node44
	node80--> |"expr"| node105
	node81("<div>I81:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>rel → expr >= ·expr <br>expr → ·expr - term <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·( expr <br></div>")
	node81--> |"{"| node54
	node81--> |"term"| node52
	node81--> |"true"| node50
	node81--> |"id"| node51
	node81--> |"factor"| node49
	node81--> |"false"| node48
	node81--> |"num"| node53
	node81--> |"!"| node47
	node81--> |"("| node46
	node81--> |"-"| node45
	node81--> |"unary"| node44
	node81--> |"expr"| node106
	node82("<div>I82:<br>while_loop → while ( bool stmt_or_block ·<br></div>")
	node83("<div>I83:<br>stmt_or_block → block ·<br></div>")
	node84("<div>I84:<br>stmt_or_block → stmt ·<br></div>")
	node85("<div>I85:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ id ] = expr ; <br>array_assignment → ·id [ num ] = expr ; <br>declaration → ·array_declaration ; <br>if_stmt → ·if ( bool stmt_or_block block_tail <br>declaration → ·basics id ; <br>while_loop → while ( bool ) ·stmt_or_block <br>assignment → ·id = expr ; <br>stmt_or_block → ·block <br>assignment → ·id = ; <br>break_stmt → ·break ; <br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>while_loop → ·while ( bool stmt_or_block <br>block → ·{ declarations stmts } <br>stmt → ·while_loop <br>stmt_or_block → ·stmt <br>block → ·{ declarations stmts <br>stmt → ·if_stmt <br>stmt → ·break_stmt <br></div>")
	node85--> |"{"| node11
	node85--> |"while"| node28
	node85--> |"id"| node27
	node85--> |"if"| node29
	node85--> |"assignment"| node19
	node85--> |"int"| node6
	node85--> |"block"| node83
	node85--> |"basics"| node13
	node85--> |"if_stmt"| node20
	node85--> |"float"| node4
	node85--> |"stmt_or_block"| node107
	node85--> |"while_loop"| node22
	node85--> |"array_assignment"| node30
	node85--> |"void"| node5
	node85--> |"declaration"| node21
	node85--> |"break_stmt"| node23
	node85--> |"array_declaration"| node16
	node85--> |"stmt"| node84
	node85--> |"break"| node25
	node86("<div>I86:<br>factor → ·false <br>factor → ·true <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>factor → ·num <br>equality → equality == ·rel <br>expr → ·expr + term <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·{ expr } <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br></div>")
	node86--> |"{"| node54
	node86--> |"id"| node51
	node86--> |"factor"| node49
	node86--> |"false"| node48
	node86--> |"num"| node53
	node86--> |"!"| node47
	node86--> |"("| node46
	node86--> |"term"| node52
	node86--> |"true"| node50
	node86--> |"rel"| node108
	node86--> |"-"| node45
	node86--> |"unary"| node44
	node86--> |"expr"| node58
	node87("<div>I87:<br>factor → ·false <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>factor → ·true <br>equality → equality != ·rel <br>expr → ·expr - term <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br></div>")
	node87--> |"{"| node54
	node87--> |"id"| node51
	node87--> |"factor"| node49
	node87--> |"false"| node48
	node87--> |"num"| node53
	node87--> |"!"| node47
	node87--> |"("| node46
	node87--> |"term"| node52
	node87--> |"true"| node50
	node87--> |"rel"| node109
	node87--> |"-"| node45
	node87--> |"unary"| node44
	node87--> |"expr"| node58
	node88("<div>I88:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>term → ·term * unary <br>join → join && ·equality <br>equality → ·rel <br>equality → ·equality == rel <br>equality → ·equality != rel <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br></div>")
	node88--> |"{"| node54
	node88--> |"expr"| node58
	node88--> |"equality"| node110
	node88--> |"unary"| node44
	node88--> |"-"| node45
	node88--> |"true"| node50
	node88--> |"rel"| node62
	node88--> |"term"| node52
	node88--> |"("| node46
	node88--> |"num"| node53
	node88--> |"!"| node47
	node88--> |"false"| node48
	node88--> |"factor"| node49
	node88--> |"id"| node51
	node89("<div>I89:<br>block_tail → ·else if ( bool stmt_or_block block_tail <br>block_tail → ·else stmt_or_block <br>block_tail → ·else if ( bool ) stmt_or_block block_tail <br>block_tail → ε ·<br>if_stmt → if ( bool stmt_or_block ·block_tail <br></div>")
	node89--> |"else"| node112
	node89--> |"block_tail"| node111
	node90("<div>I90:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ id ] = expr ; <br>array_assignment → ·id [ num ] = expr ; <br>declaration → ·array_declaration ; <br>if_stmt → ·if ( bool stmt_or_block block_tail <br>declaration → ·basics id ; <br>stmt → ·while_loop <br>block → ·{ declarations stmts <br>stmt_or_block → ·stmt <br>assignment → ·id = expr ; <br>stmt_or_block → ·block <br>assignment → ·id = ; <br>break_stmt → ·break ; <br>if_stmt → if ( bool ) ·stmt_or_block block_tail <br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>while_loop → ·while ( bool stmt_or_block <br>block → ·{ declarations stmts } <br>stmt → ·if_stmt <br>stmt → ·break_stmt <br></div>")
	node90--> |"{"| node11
	node90--> |"while"| node28
	node90--> |"id"| node27
	node90--> |"if"| node29
	node90--> |"assignment"| node19
	node90--> |"int"| node6
	node90--> |"block"| node83
	node90--> |"basics"| node13
	node90--> |"if_stmt"| node20
	node90--> |"float"| node4
	node90--> |"stmt_or_block"| node113
	node90--> |"while_loop"| node22
	node90--> |"array_assignment"| node30
	node90--> |"void"| node5
	node90--> |"declaration"| node21
	node90--> |"break_stmt"| node23
	node90--> |"array_declaration"| node16
	node90--> |"stmt"| node84
	node90--> |"break"| node25
	node91("<div>I91:<br>array_declaration → basics id [ id ] = ·{ array_init } <br></div>")
	node91--> |"{"| node114
	node92("<div>I92:<br>array_declaration → basics id [ num ] = ·{ array_init } <br></div>")
	node92--> |"{"| node115
	node93("<div>I93:<br>term → term ·/ unary <br>term → term ·* unary <br>expr → expr + term ·<br></div>")
	node93--> |"*"| node74
	node93--> |"/"| node73
	node94("<div>I94:<br>term → term ·/ unary <br>term → term ·* unary <br>expr → expr - term ·<br></div>")
	node94--> |"*"| node74
	node94--> |"/"| node73
	node95("<div>I95:<br>factor → ( expr ) ·<br></div>")
	node96("<div>I96:<br>factor → id [ id ·] <br>factor → id [ id ·] <br></div>")
	node96--> |"]"| node116
	node97("<div>I97:<br>factor → id [ num ·] <br>factor → id [ num ·<br></div>")
	node97--> |"]"| node117
	node98("<div>I98:<br>term → term / unary ·<br></div>")
	node99("<div>I99:<br>term → term * unary ·<br></div>")
	node100("<div>I100:<br>expr → { expr } ·<br></div>")
	node101("<div>I101:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>array_assignment → id [ id ] = ·expr ; <br>unary → ·! unary <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·( expr <br></div>")
	node101--> |"{"| node54
	node101--> |"term"| node52
	node101--> |"true"| node50
	node101--> |"id"| node51
	node101--> |"factor"| node49
	node101--> |"false"| node48
	node101--> |"num"| node53
	node101--> |"!"| node47
	node101--> |"("| node46
	node101--> |"-"| node45
	node101--> |"unary"| node44
	node101--> |"expr"| node118
	node102("<div>I102:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>array_assignment → id [ num ] = ·expr ; <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr <br></div>")
	node102--> |"{"| node54
	node102--> |"term"| node52
	node102--> |"true"| node50
	node102--> |"id"| node51
	node102--> |"factor"| node49
	node102--> |"false"| node48
	node102--> |"num"| node53
	node102--> |"!"| node47
	node102--> |"("| node46
	node102--> |"-"| node45
	node102--> |"unary"| node44
	node102--> |"expr"| node119
	node103("<div>I103:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr < expr ·<br></div>")
	node103--> |"-"| node67
	node103--> |"+"| node66
	node104("<div>I104:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr <= expr ·<br></div>")
	node104--> |"-"| node67
	node104--> |"+"| node66
	node105("<div>I105:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr > expr ·<br></div>")
	node105--> |"-"| node67
	node105--> |"+"| node66
	node106("<div>I106:<br>expr → expr ·+ term <br>expr → expr ·- term <br>rel → expr >= expr ·<br></div>")
	node106--> |"-"| node67
	node106--> |"+"| node66
	node107("<div>I107:<br>while_loop → while ( bool ) stmt_or_block ·<br></div>")
	node108("<div>I108:<br>equality → equality == rel ·<br></div>")
	node109("<div>I109:<br>equality → equality != rel ·<br></div>")
	node110("<div>I110:<br>equality → equality ·!= rel <br>equality → equality ·== rel <br>join → join && equality ·<br></div>")
	node110--> |"!="| node87
	node110--> |"=="| node86
	node111("<div>I111:<br>if_stmt → if ( bool stmt_or_block block_tail ·<br></div>")
	node112("<div>I112:<br>array_declaration → ·basics id [ id ] = { array_init } <br>stmt → ·break_stmt <br>stmt → ·if_stmt <br>block → ·{ declarations stmts <br>stmt_or_block → ·stmt <br>stmt → ·while_loop <br>stmt → ·declaration <br>stmt → ·assignment <br>break_stmt → ·break ; <br>stmt_or_block → ·block <br>block_tail → else ·if ( bool ) stmt_or_block block_tail <br>declaration → ·array_declaration ; <br>declaration → ·basics id ; <br>block_tail → else ·stmt_or_block <br>if_stmt → ·if ( bool stmt_or_block block_tail <br>block → ·{ declarations stmts } <br>while_loop → ·while ( bool stmt_or_block <br>stmt → ·array_assignment <br>block_tail → else ·if ( bool stmt_or_block block_tail <br>assignment → ·id = expr ; <br>assignment → ·id = ; <br>array_assignment → ·id [ num ] = expr ; <br>array_assignment → ·id [ id ] = expr ; <br>while_loop → ·while ( bool ) stmt_or_block <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>basics → ·void <br>basics → ·int <br>basics → ·float <br>array_declaration → ·basics id [ num ] <br>array_declaration → ·basics id [ num ] = { array_init } <br></div>")
	node112--> |"{"| node11
	node112--> |"while"| node28
	node112--> |"id"| node27
	node112--> |"if"| node121
	node112--> |"assignment"| node19
	node112--> |"int"| node6
	node112--> |"block"| node83
	node112--> |"basics"| node13
	node112--> |"if_stmt"| node20
	node112--> |"float"| node4
	node112--> |"stmt_or_block"| node120
	node112--> |"while_loop"| node22
	node112--> |"array_assignment"| node30
	node112--> |"void"| node5
	node112--> |"declaration"| node21
	node112--> |"break_stmt"| node23
	node112--> |"array_declaration"| node16
	node112--> |"stmt"| node84
	node112--> |"break"| node25
	node113("<div>I113:<br>block_tail → ·else if ( bool stmt_or_block block_tail <br>block_tail → ·else stmt_or_block <br>block_tail → ·else if ( bool ) stmt_or_block block_tail <br>block_tail → ε ·<br>if_stmt → if ( bool ) stmt_or_block ·block_tail <br></div>")
	node113--> |"else"| node112
	node113--> |"block_tail"| node122
	node114("<div>I114:<br>array_init → ·id <br>array_init → ·array_init , id <br>array_init → ·num <br>array_init → ·array_init , num <br>array_declaration → basics id [ id ] = { ·array_init } <br></div>")
	node114--> |"num"| node125
	node114--> |"id"| node124
	node114--> |"array_init"| node123
	node115("<div>I115:<br>array_init → ·id <br>array_init → ·array_init , id <br>array_init → ·num <br>array_init → ·array_init , num <br>array_declaration → basics id [ num ] = { ·array_init } <br></div>")
	node115--> |"num"| node125
	node115--> |"id"| node124
	node115--> |"array_init"| node126
	node116("<div>I116:<br>factor → id [ id ] ·<br>factor → id [ id ] ·<br></div>")
	node117("<div>I117:<br>factor → id [ num ] ·<br></div>")
	node118("<div>I118:<br>expr → expr ·- term <br>expr → expr ·+ term <br>array_assignment → id [ id ] = expr ·; <br></div>")
	node118--> |";"| node127
	node118--> |"-"| node67
	node118--> |"+"| node66
	node119("<div>I119:<br>expr → expr ·- term <br>expr → expr ·+ term <br>array_assignment → id [ num ] = expr ·; <br></div>")
	node119--> |";"| node128
	node119--> |"-"| node67
	node119--> |"+"| node66
	node120("<div>I120:<br>block_tail → else stmt_or_block ·<br></div>")
	node121("<div>I121:<br>if_stmt → if ·( bool ) stmt_or_block block_tail <br>block_tail → else if ·( bool stmt_or_block block_tail <br>if_stmt → if ·( bool stmt_or_block block_tail <br>block_tail → else if ·( bool ) stmt_or_block block_tail <br></div>")
	node121--> |"("| node129
	node122("<div>I122:<br>if_stmt → if ( bool ) stmt_or_block block_tail ·<br></div>")
	node123("<div>I123:<br>array_declaration → basics id [ id ] = { array_init ·} <br>array_init → array_init ·, num <br>array_init → array_init ·, id <br></div>")
	node123--> |","| node131
	node123--> |"}"| node130
	node124("<div>I124:<br>array_init → id ·<br></div>")
	node125("<div>I125:<br>array_init → num ·<br></div>")
	node126("<div>I126:<br>array_declaration → basics id [ num ] = { array_init ·} <br>array_init → array_init ·, num <br>array_init → array_init ·, id <br></div>")
	node126--> |","| node131
	node126--> |"}"| node132
	node127("<div>I127:<br>array_assignment → id [ id ] = expr ; ·<br></div>")
	node128("<div>I128:<br>array_assignment → id [ num ] = expr ; ·<br></div>")
	node129("<div>I129:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>rel → ·expr > expr <br>rel → ·expr <= expr <br>rel → ·expr < expr <br>equality → ·equality == rel <br>join → ·equality <br>join → ·join && equality <br>bool → ·join <br>equality → ·equality != rel <br>if_stmt → if ( ·bool stmt_or_block block_tail <br>unary → ·factor <br>equality → ·rel <br>block_tail → else if ( ·bool stmt_or_block block_tail <br>block_tail → else if ( ·bool ) stmt_or_block block_tail <br>factor → ·( expr ) <br>if_stmt → if ( ·bool ) stmt_or_block block_tail <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>factor → ·( expr <br>factor → ·id <br>factor → ·id [ num ] <br></div>")
	node129--> |"{"| node54
	node129--> |"num"| node53
	node129--> |"expr"| node58
	node129--> |"equality"| node60
	node129--> |"unary"| node44
	node129--> |"-"| node45
	node129--> |"join"| node61
	node129--> |"term"| node52
	node129--> |"bool"| node133
	node129--> |"rel"| node62
	node129--> |"true"| node50
	node129--> |"("| node46
	node129--> |"!"| node47
	node129--> |"false"| node48
	node129--> |"factor"| node49
	node129--> |"id"| node51
	node130("<div>I130:<br>array_declaration → basics id [ id ] = { array_init } ·<br></div>")
	node131("<div>I131:<br>array_init → array_init , ·id <br>array_init → array_init , ·num <br></div>")
	node131--> |"num"| node135
	node131--> |"id"| node134
	node132("<div>I132:<br>array_declaration → basics id [ num ] = { array_init } ·<br></div>")
	node133("<div>I133:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>stmt → ·if_stmt <br>block_tail → else if ( bool ·) stmt_or_block block_tail <br>stmt → ·while_loop <br>block → ·{ declarations stmts } <br>block_tail → else if ( bool ·stmt_or_block block_tail <br>while_loop → ·while ( bool stmt_or_block <br>stmt → ·array_assignment <br>stmt → ·declaration <br>stmt → ·assignment <br>break_stmt → ·break ; <br>stmt_or_block → ·stmt <br>block → ·{ declarations stmts <br>if_stmt → if ( bool ·) stmt_or_block block_tail <br>declaration → ·array_declaration ; <br>stmt → ·break_stmt <br>stmt_or_block → ·block <br>if_stmt → if ( bool ·stmt_or_block block_tail <br>assignment → ·id = expr ; <br>assignment → ·id = ; <br>declaration → ·basics id ; <br>if_stmt → ·if ( bool stmt_or_block block_tail <br>array_assignment → ·id [ num ] = expr ; <br>array_assignment → ·id [ id ] = expr ; <br>while_loop → ·while ( bool ) stmt_or_block <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>basics → ·void <br>basics → ·int <br>basics → ·float <br>array_declaration → ·basics id [ num ] <br></div>")
	node133--> |"{"| node11
	node133--> |"while"| node28
	node133--> |")"| node137
	node133--> |"id"| node27
	node133--> |"if"| node29
	node133--> |"assignment"| node19
	node133--> |"int"| node6
	node133--> |"block"| node83
	node133--> |"basics"| node13
	node133--> |"if_stmt"| node20
	node133--> |"float"| node4
	node133--> |"stmt_or_block"| node136
	node133--> |"while_loop"| node22
	node133--> |"array_assignment"| node30
	node133--> |"void"| node5
	node133--> |"declaration"| node21
	node133--> |"break_stmt"| node23
	node133--> |"array_declaration"| node16
	node133--> |"stmt"| node84
	node133--> |"break"| node25
	node134("<div>I134:<br>array_init → array_init , id ·<br></div>")
	node135("<div>I135:<br>array_init → array_init , num ·<br></div>")
	node136("<div>I136:<br>block_tail → ·else if ( bool stmt_or_block block_tail <br>block_tail → ·else stmt_or_block <br>block_tail → ·else if ( bool ) stmt_or_block block_tail <br>block_tail → ε ·<br>if_stmt → if ( bool stmt_or_block ·block_tail <br>block_tail → else if ( bool stmt_or_block ·block_tail <br></div>")
	node136--> |"else"| node112
	node136--> |"block_tail"| node138
	node137("<div>I137:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ id ] = expr ; <br>array_assignment → ·id [ num ] = expr ; <br>declaration → ·array_declaration ; <br>if_stmt → ·if ( bool stmt_or_block block_tail <br>declaration → ·basics id ; <br>assignment → ·id = ; <br>stmt → ·break_stmt <br>stmt → ·while_loop <br>block → ·{ declarations stmts <br>stmt_or_block → ·stmt <br>assignment → ·id = expr ; <br>stmt_or_block → ·block <br>break_stmt → ·break ; <br>if_stmt → if ( bool ) ·stmt_or_block block_tail <br>stmt → ·assignment <br>stmt → ·declaration <br>block_tail → else if ( bool ) ·stmt_or_block block_tail <br>stmt → ·array_assignment <br>while_loop → ·while ( bool stmt_or_block <br>block → ·{ declarations stmts } <br>stmt → ·if_stmt <br></div>")
	node137--> |"{"| node11
	node137--> |"while"| node28
	node137--> |"id"| node27
	node137--> |"if"| node29
	node137--> |"assignment"| node19
	node137--> |"int"| node6
	node137--> |"block"| node83
	node137--> |"basics"| node13
	node137--> |"if_stmt"| node20
	node137--> |"float"| node4
	node137--> |"stmt_or_block"| node139
	node137--> |"while_loop"| node22
	node137--> |"array_assignment"| node30
	node137--> |"void"| node5
	node137--> |"declaration"| node21
	node137--> |"break_stmt"| node23
	node137--> |"array_declaration"| node16
	node137--> |"stmt"| node84
	node137--> |"break"| node25
	node138("<div>I138:<br>block_tail → else if ( bool stmt_or_block block_tail ·<br>if_stmt → if ( bool stmt_or_block block_tail ·<br></div>")
	node139("<div>I139:<br>block_tail → ·else if ( bool stmt_or_block block_tail <br>block_tail → ·else stmt_or_block <br>block_tail → ·else if ( bool ) stmt_or_block block_tail <br>block_tail → ε ·<br>block_tail → else if ( bool ) stmt_or_block ·block_tail <br>if_stmt → if ( bool ) stmt_or_block ·block_tail <br></div>")
	node139--> |"else"| node112
	node139--> |"block_tail"| node140
	node140("<div>I140:<br>if_stmt → if ( bool ) stmt_or_block block_tail ·<br>block_tail → else if ( bool ) stmt_or_block block_tail ·<br></div>")
```
