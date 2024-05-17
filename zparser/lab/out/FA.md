## 产生式

- S → program 
- program → basics id ( ) block 
- program → basics id ( block 
- block → { declarations stmts } 
- block → { declarations stmts 
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
- while_loop → while ( bool stmt_or_block 
- stmt_or_block → stmt 
- stmt_or_block → block 
- if_stmt → if ( bool ) stmt_or_block block_tail 
- if_stmt → if ( bool stmt_or_block block_tail 
- block_tail → ε 
- block_tail → else stmt_or_block 
- block_tail → else if ( bool ) stmt_or_block block_tail 
- block_tail → else if ( bool stmt_or_block block_tail 
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
- factor → ( expr 
- factor → id 
- factor → id [ num ] 
- factor → id [ num 
- factor → id [ id ] 
- factor → id [ id ] 
- factor → num 
- factor → true 
- factor → false 
- break_stmt → break ; 
- START → S 

## FA Graph

```mermaid
	graph LR
	node0("<div>I0:<br>basics → ·float <br>basics → ·int <br>basics → ·void <br>program → ·basics id ( block <br>program → ·basics id ( ) block <br>S → ·program <br>START → ·S <br></div>")
	node0--> |"int"| node6
	node0--> |"void"| node5
	node0--> |"float"| node4
	node0--> |"program"| node3
	node0--> |"S"| node2
	node0--> |"basics"| node1
	node1("<div>I1:<br>program → basics ·id ( ) block <br>program → basics ·id ( block <br></div>")
	node1--> |"id"| node7
	node2("<div>I2:<br>START → S ·<br></div>")
	node3("<div>I3:<br>S → program ·<br></div>")
	node4("<div>I4:<br>basics → float ·<br></div>")
	node5("<div>I5:<br>basics → void ·<br></div>")
	node6("<div>I6:<br>basics → int ·<br></div>")
	node7("<div>I7:<br>program → basics id ·( block <br>program → basics id ·( ) block <br></div>")
	node7--> |"("| node8
	node8("<div>I8:<br>block → ·{ declarations stmts } <br>program → basics id ( ·) block <br>block → ·{ declarations stmts <br>program → basics id ( ·block <br></div>")
	node8--> |"{"| node11
	node8--> |")"| node10
	node8--> |"block"| node9
	node9("<div>I9:<br>program → basics id ( block ·<br></div>")
	node10("<div>I10:<br>block → ·{ declarations stmts <br>block → ·{ declarations stmts } <br>program → basics id ( ) ·block <br></div>")
	node10--> |"{"| node11
	node10--> |"block"| node12
	node11("<div>I11:<br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>declaration → ·array_declaration ; <br>declaration → ·basics id ; <br>declarations → ε ·<br>declarations → ·declaration declarations <br>block → { ·declarations stmts <br>array_declaration → ·basics id [ id ] = { array_init } <br>block → { ·declarations stmts } <br></div>")
	node11--> |"int"| node6
	node11--> |"void"| node5
	node11--> |"array_declaration"| node16
	node11--> |"float"| node4
	node11--> |"declarations"| node15
	node11--> |"declaration"| node14
	node11--> |"basics"| node13
	node12("<div>I12:<br>program → basics id ( ) block ·<br></div>")
	node13("<div>I13:<br>array_declaration → basics ·id [ id ] = { array_init } <br>declaration → basics ·id ; <br>array_declaration → basics ·id [ num ] <br>array_declaration → basics ·id [ num ] = { array_init } <br></div>")
	node13--> |"id"| node17
	node14("<div>I14:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>declaration → ·array_declaration ; <br>declarations → ε ·<br>declarations → ·declaration declarations <br>declaration → ·basics id ; <br>declarations → declaration ·declarations <br></div>")
	node14--> |"int"| node6
	node14--> |"void"| node5
	node14--> |"array_declaration"| node16
	node14--> |"float"| node4
	node14--> |"declarations"| node18
	node14--> |"declaration"| node14
	node14--> |"basics"| node13
	node15("<div>I15:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool stmt_or_block block_tail <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool stmt_or_block <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ num ] = expr ; <br>array_assignment → ·id [ id ] = expr ; <br>block → { declarations ·stmts <br>assignment → ·id = expr ; <br>block → { declarations ·stmts } <br>declaration → ·basics id ; <br>stmts → ·stmt stmts <br>stmts → ε ·<br>stmt → ·declaration <br>stmt → ·assignment <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>stmt → ·if_stmt <br>stmt → ·break_stmt <br>declaration → ·array_declaration ; <br></div>")
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
	node17("<div>I17:<br>array_declaration → basics id ·[ num ] = { array_init } <br>array_declaration → basics id ·[ num ] <br>declaration → basics id ·; <br>array_declaration → basics id ·[ id ] = { array_init } <br></div>")
	node17--> |";"| node33
	node17--> |"["| node32
	node18("<div>I18:<br>declarations → declaration declarations ·<br></div>")
	node19("<div>I19:<br>stmt → assignment ·<br></div>")
	node20("<div>I20:<br>stmt → if_stmt ·<br></div>")
	node21("<div>I21:<br>stmt → declaration ·<br></div>")
	node22("<div>I22:<br>stmt → while_loop ·<br></div>")
	node23("<div>I23:<br>stmt → break_stmt ·<br></div>")
	node24("<div>I24:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool stmt_or_block block_tail <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool stmt_or_block <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ id ] = expr ; <br>stmts → stmt ·stmts <br>stmt → ·assignment <br>stmts → ·stmt stmts <br>stmts → ε ·<br>stmt → ·declaration <br>array_assignment → ·id [ num ] = expr ; <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>stmt → ·if_stmt <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>declaration → ·basics id ; <br>declaration → ·array_declaration ; <br></div>")
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
	node27("<div>I27:<br>assignment → id ·= expr ; <br>array_assignment → id ·[ id ] = expr ; <br>array_assignment → id ·[ num ] = expr ; <br></div>")
	node27--> |"["| node38
	node27--> |"="| node37
	node28("<div>I28:<br>while_loop → while ·( bool ) stmt_or_block <br>while_loop → while ·( bool stmt_or_block <br></div>")
	node28--> |"("| node39
	node29("<div>I29:<br>if_stmt → if ·( bool ) stmt_or_block block_tail <br>if_stmt → if ·( bool stmt_or_block block_tail <br></div>")
	node29--> |"("| node40
	node30("<div>I30:<br>stmt → array_assignment ·<br></div>")
	node31("<div>I31:<br>declaration → array_declaration ; ·<br></div>")
	node32("<div>I32:<br>array_declaration → basics id [ ·id ] = { array_init } <br>array_declaration → basics id [ ·num ] <br>array_declaration → basics id [ ·num ] = { array_init } <br></div>")
	node32--> |"num"| node42
	node32--> |"id"| node41
	node33("<div>I33:<br>declaration → basics id ; ·<br></div>")
	node34("<div>I34:<br>stmts → stmt stmts ·<br></div>")
	node35("<div>I35:<br>break_stmt → break ; ·<br></div>")
	node36("<div>I36:<br>block → { declarations stmts } ·<br></div>")
	node37("<div>I37:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>assignment → id = ·expr ; <br>term → ·term * unary <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·( expr <br></div>")
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
	node38("<div>I38:<br>array_assignment → id [ ·num ] = expr ; <br>array_assignment → id [ ·id ] = expr ; <br></div>")
	node38--> |"num"| node56
	node38--> |"id"| node55
	node39("<div>I39:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>rel → ·expr <br>rel → ·expr >= expr <br>rel → ·expr > expr <br>rel → ·expr <= expr <br>rel → ·expr < expr <br>equality → ·rel <br>equality → ·equality != rel <br>equality → ·equality == rel <br>join → ·equality <br>join → ·join && equality <br>bool → ·join <br>while_loop → while ( ·bool stmt_or_block <br>term → ·term / unary <br>while_loop → while ( ·bool ) stmt_or_block <br>term → ·term * unary <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·( expr <br>factor → ·id <br>factor → ·id [ num ] <br>factor → ·id [ num <br>factor → ·id [ id ] <br></div>")
	node39--> |"{"| node54
	node39--> |"num"| node53
	node39--> |"expr"| node57
	node39--> |"equality"| node59
	node39--> |"unary"| node44
	node39--> |"-"| node45
	node39--> |"join"| node60
	node39--> |"term"| node52
	node39--> |"bool"| node58
	node39--> |"rel"| node61
	node39--> |"true"| node50
	node39--> |"("| node46
	node39--> |"!"| node47
	node39--> |"false"| node48
	node39--> |"factor"| node49
	node39--> |"id"| node51
	node40("<div>I40:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>rel → ·expr <br>rel → ·expr >= expr <br>rel → ·expr > expr <br>rel → ·expr <= expr <br>rel → ·expr < expr <br>equality → ·rel <br>equality → ·equality != rel <br>equality → ·equality == rel <br>join → ·equality <br>join → ·join && equality <br>bool → ·join <br>if_stmt → if ( ·bool stmt_or_block block_tail <br>if_stmt → if ( ·bool ) stmt_or_block block_tail <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·( expr <br>factor → ·id <br>factor → ·id [ num ] <br>factor → ·id [ num <br>factor → ·id [ id ] <br></div>")
	node40--> |"{"| node54
	node40--> |"num"| node53
	node40--> |"expr"| node57
	node40--> |"equality"| node59
	node40--> |"unary"| node44
	node40--> |"-"| node45
	node40--> |"join"| node60
	node40--> |"term"| node52
	node40--> |"bool"| node62
	node40--> |"rel"| node61
	node40--> |"true"| node50
	node40--> |"("| node46
	node40--> |"!"| node47
	node40--> |"false"| node48
	node40--> |"factor"| node49
	node40--> |"id"| node51
	node41("<div>I41:<br>array_declaration → basics id [ id ·] = { array_init } <br></div>")
	node41--> |"]"| node63
	node42("<div>I42:<br>array_declaration → basics id [ num ·] = { array_init } <br>array_declaration → basics id [ num ·] <br></div>")
	node42--> |"]"| node64
	node43("<div>I43:<br>expr → expr ·- term <br>expr → expr ·+ term <br>assignment → id = expr ·; <br></div>")
	node43--> |";"| node67
	node43--> |"-"| node66
	node43--> |"+"| node65
	node44("<div>I44:<br>term → unary ·<br></div>")
	node45("<div>I45:<br>factor → ·false <br>unary → - ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·( expr <br>factor → ·id <br>factor → ·id [ num ] <br>factor → ·id [ num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·num <br>factor → ·true <br></div>")
	node45--> |"true"| node50
	node45--> |"id"| node51
	node45--> |"factor"| node49
	node45--> |"false"| node48
	node45--> |"num"| node53
	node45--> |"!"| node47
	node45--> |"("| node46
	node45--> |"-"| node45
	node45--> |"unary"| node68
	node46("<div>I46:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·( expr <br>factor → ·id <br>factor → ( ·expr ) <br>factor → ( ·expr <br>unary → ·factor <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>factor → ·( expr ) <br></div>")
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
	node46--> |"expr"| node69
	node47("<div>I47:<br>factor → ·false <br>unary → ! ·unary <br>factor → ·true <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·( expr <br>factor → ·id <br>factor → ·id [ num ] <br>factor → ·id [ num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·num <br></div>")
	node47--> |"true"| node50
	node47--> |"id"| node51
	node47--> |"factor"| node49
	node47--> |"false"| node48
	node47--> |"num"| node53
	node47--> |"!"| node47
	node47--> |"("| node46
	node47--> |"-"| node45
	node47--> |"unary"| node70
	node48("<div>I48:<br>factor → false ·<br></div>")
	node49("<div>I49:<br>unary → factor ·<br></div>")
	node50("<div>I50:<br>factor → true ·<br></div>")
	node51("<div>I51:<br>factor → id ·<br>factor → id ·[ num ] <br>factor → id ·[ num <br>factor → id ·[ id ] <br>factor → id ·[ id ] <br></div>")
	node51--> |"["| node71
	node52("<div>I52:<br>term → term ·/ unary <br>expr → term ·<br>term → term ·* unary <br></div>")
	node52--> |"*"| node73
	node52--> |"/"| node72
	node53("<div>I53:<br>factor → num ·<br></div>")
	node54("<div>I54:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>expr → { ·expr } <br>factor → ·( expr <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br></div>")
	node54--> |"{"| node54
	node54--> |"term"| node52
	node54--> |"true"| node50
	node54--> |"id"| node51
	node54--> |"factor"| node49
	node54--> |"false"| node48
	node54--> |"num"| node53
	node54--> |"!"| node47
	node54--> |"("| node46
	node54--> |"-"| node45
	node54--> |"unary"| node44
	node54--> |"expr"| node74
	node55("<div>I55:<br>array_assignment → id [ id ·] = expr ; <br></div>")
	node55--> |"]"| node75
	node56("<div>I56:<br>array_assignment → id [ num ·] = expr ; <br></div>")
	node56--> |"]"| node76
	node57("<div>I57:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr ·< expr <br>rel → expr ·<= expr <br>rel → expr ·> expr <br>rel → expr ·>= expr <br>rel → expr ·<br></div>")
	node57--> |">="| node80
	node57--> |">"| node79
	node57--> |"<="| node78
	node57--> |"-"| node66
	node57--> |"<"| node77
	node57--> |"+"| node65
	node58("<div>I58:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool stmt_or_block block_tail <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool stmt_or_block <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ id ] = expr ; <br>array_assignment → ·id [ num ] = expr ; <br>declaration → ·array_declaration ; <br>declaration → ·basics id ; <br>array_declaration → ·basics id [ num ] <br>while_loop → while ( bool ·stmt_or_block <br>while_loop → while ( bool ·) stmt_or_block <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt_or_block → ·stmt <br>block → ·{ declarations stmts } <br>stmt → ·while_loop <br>stmt_or_block → ·block <br>block → ·{ declarations stmts <br>stmt → ·if_stmt <br></div>")
	node58--> |"{"| node11
	node58--> |"while"| node28
	node58--> |")"| node84
	node58--> |"id"| node27
	node58--> |"if"| node29
	node58--> |"assignment"| node19
	node58--> |"int"| node6
	node58--> |"block"| node82
	node58--> |"basics"| node13
	node58--> |"if_stmt"| node20
	node58--> |"float"| node4
	node58--> |"stmt_or_block"| node81
	node58--> |"while_loop"| node22
	node58--> |"array_assignment"| node30
	node58--> |"void"| node5
	node58--> |"declaration"| node21
	node58--> |"break_stmt"| node23
	node58--> |"array_declaration"| node16
	node58--> |"stmt"| node83
	node58--> |"break"| node25
	node59("<div>I59:<br>join → equality ·<br>equality → equality ·== rel <br>equality → equality ·!= rel <br></div>")
	node59--> |"!="| node86
	node59--> |"=="| node85
	node60("<div>I60:<br>bool → join ·<br>join → join ·&& equality <br></div>")
	node60--> |"&&"| node87
	node61("<div>I61:<br>equality → rel ·<br></div>")
	node62("<div>I62:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool stmt_or_block block_tail <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool stmt_or_block <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ id ] = expr ; <br>array_assignment → ·id [ num ] = expr ; <br>declaration → ·array_declaration ; <br>if_stmt → if ( bool ·stmt_or_block block_tail <br>declaration → ·basics id ; <br>if_stmt → if ( bool ·) stmt_or_block block_tail <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt_or_block → ·stmt <br>block → ·{ declarations stmts } <br>stmt → ·while_loop <br>stmt_or_block → ·block <br>block → ·{ declarations stmts <br>stmt → ·if_stmt <br></div>")
	node62--> |"{"| node11
	node62--> |"while"| node28
	node62--> |")"| node89
	node62--> |"id"| node27
	node62--> |"if"| node29
	node62--> |"assignment"| node19
	node62--> |"int"| node6
	node62--> |"block"| node82
	node62--> |"basics"| node13
	node62--> |"if_stmt"| node20
	node62--> |"float"| node4
	node62--> |"stmt_or_block"| node88
	node62--> |"while_loop"| node22
	node62--> |"array_assignment"| node30
	node62--> |"void"| node5
	node62--> |"declaration"| node21
	node62--> |"break_stmt"| node23
	node62--> |"array_declaration"| node16
	node62--> |"stmt"| node83
	node62--> |"break"| node25
	node63("<div>I63:<br>array_declaration → basics id [ id ] ·= { array_init } <br></div>")
	node63--> |"="| node90
	node64("<div>I64:<br>array_declaration → basics id [ num ] ·<br>array_declaration → basics id [ num ] ·= { array_init } <br></div>")
	node64--> |"="| node91
	node65("<div>I65:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>expr → expr + ·term <br>factor → ·( expr ) <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr <br>factor → ·id <br>factor → ·id [ num ] <br>factor → ·id [ num <br>factor → ·id [ id ] <br></div>")
	node65--> |"term"| node92
	node65--> |"true"| node50
	node65--> |"id"| node51
	node65--> |"factor"| node49
	node65--> |"false"| node48
	node65--> |"num"| node53
	node65--> |"!"| node47
	node65--> |"("| node46
	node65--> |"-"| node45
	node65--> |"unary"| node44
	node66("<div>I66:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>expr → expr - ·term <br>factor → ·( expr <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br>factor → ·id [ num <br>factor → ·id [ id ] <br></div>")
	node66--> |"term"| node93
	node66--> |"true"| node50
	node66--> |"id"| node51
	node66--> |"factor"| node49
	node66--> |"false"| node48
	node66--> |"num"| node53
	node66--> |"!"| node47
	node66--> |"("| node46
	node66--> |"-"| node45
	node66--> |"unary"| node44
	node67("<div>I67:<br>assignment → id = expr ; ·<br></div>")
	node68("<div>I68:<br>unary → - unary ·<br></div>")
	node69("<div>I69:<br>expr → expr ·- term <br>expr → expr ·+ term <br>factor → ( expr ·<br>factor → ( expr ·) <br></div>")
	node69--> |")"| node94
	node69--> |"-"| node66
	node69--> |"+"| node65
	node70("<div>I70:<br>unary → ! unary ·<br></div>")
	node71("<div>I71:<br>factor → id [ ·id ] <br>factor → id [ ·id ] <br>factor → id [ ·num <br>factor → id [ ·num ] <br></div>")
	node71--> |"num"| node96
	node71--> |"id"| node95
	node72("<div>I72:<br>factor → ·false <br>term → term / ·unary <br>unary → ·factor <br>unary → ·! unary <br>unary → ·- unary <br>factor → ·( expr ) <br>factor → ·( expr <br>factor → ·id <br>factor → ·id [ num ] <br>factor → ·id [ num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·num <br>factor → ·true <br></div>")
	node72--> |"true"| node50
	node72--> |"id"| node51
	node72--> |"factor"| node49
	node72--> |"false"| node48
	node72--> |"num"| node53
	node72--> |"!"| node47
	node72--> |"("| node46
	node72--> |"-"| node45
	node72--> |"unary"| node97
	node73("<div>I73:<br>factor → ·false <br>term → term * ·unary <br>factor → ·id [ num ] <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·( expr <br>factor → ·id <br>factor → ·id [ num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·num <br>factor → ·true <br></div>")
	node73--> |"true"| node50
	node73--> |"id"| node51
	node73--> |"factor"| node49
	node73--> |"false"| node48
	node73--> |"num"| node53
	node73--> |"!"| node47
	node73--> |"("| node46
	node73--> |"-"| node45
	node73--> |"unary"| node98
	node74("<div>I74:<br>expr → expr ·+ term <br>expr → expr ·- term <br>expr → { expr ·} <br></div>")
	node74--> |"}"| node99
	node74--> |"-"| node66
	node74--> |"+"| node65
	node75("<div>I75:<br>array_assignment → id [ id ] ·= expr ; <br></div>")
	node75--> |"="| node100
	node76("<div>I76:<br>array_assignment → id [ num ] ·= expr ; <br></div>")
	node76--> |"="| node101
	node77("<div>I77:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>rel → expr < ·expr <br>term → ·term * unary <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·( expr <br></div>")
	node77--> |"{"| node54
	node77--> |"term"| node52
	node77--> |"true"| node50
	node77--> |"id"| node51
	node77--> |"factor"| node49
	node77--> |"false"| node48
	node77--> |"num"| node53
	node77--> |"!"| node47
	node77--> |"("| node46
	node77--> |"-"| node45
	node77--> |"unary"| node44
	node77--> |"expr"| node102
	node78("<div>I78:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>rel → expr <= ·expr <br>term → ·term / unary <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·( expr <br></div>")
	node78--> |"{"| node54
	node78--> |"term"| node52
	node78--> |"true"| node50
	node78--> |"id"| node51
	node78--> |"factor"| node49
	node78--> |"false"| node48
	node78--> |"num"| node53
	node78--> |"!"| node47
	node78--> |"("| node46
	node78--> |"-"| node45
	node78--> |"unary"| node44
	node78--> |"expr"| node103
	node79("<div>I79:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>rel → expr > ·expr <br>expr → ·expr + term <br>expr → ·{ expr } <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·( expr <br></div>")
	node79--> |"{"| node54
	node79--> |"term"| node52
	node79--> |"true"| node50
	node79--> |"id"| node51
	node79--> |"factor"| node49
	node79--> |"false"| node48
	node79--> |"num"| node53
	node79--> |"!"| node47
	node79--> |"("| node46
	node79--> |"-"| node45
	node79--> |"unary"| node44
	node79--> |"expr"| node104
	node80("<div>I80:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>rel → expr >= ·expr <br>expr → ·expr - term <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·( expr <br></div>")
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
	node81("<div>I81:<br>while_loop → while ( bool stmt_or_block ·<br></div>")
	node82("<div>I82:<br>stmt_or_block → block ·<br></div>")
	node83("<div>I83:<br>stmt_or_block → stmt ·<br></div>")
	node84("<div>I84:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool stmt_or_block block_tail <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool stmt_or_block <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ id ] = expr ; <br>array_assignment → ·id [ num ] = expr ; <br>declaration → ·array_declaration ; <br>while_loop → while ( bool ) ·stmt_or_block <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>declaration → ·basics id ; <br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt_or_block → ·stmt <br>block → ·{ declarations stmts } <br>stmt → ·while_loop <br>stmt_or_block → ·block <br>block → ·{ declarations stmts <br>stmt → ·if_stmt <br></div>")
	node84--> |"{"| node11
	node84--> |"while"| node28
	node84--> |"id"| node27
	node84--> |"if"| node29
	node84--> |"assignment"| node19
	node84--> |"int"| node6
	node84--> |"block"| node82
	node84--> |"basics"| node13
	node84--> |"if_stmt"| node20
	node84--> |"float"| node4
	node84--> |"stmt_or_block"| node106
	node84--> |"while_loop"| node22
	node84--> |"array_assignment"| node30
	node84--> |"void"| node5
	node84--> |"declaration"| node21
	node84--> |"break_stmt"| node23
	node84--> |"array_declaration"| node16
	node84--> |"stmt"| node83
	node84--> |"break"| node25
	node85("<div>I85:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>equality → equality == ·rel <br>rel → ·expr <= expr <br>rel → ·expr < expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br></div>")
	node85--> |"{"| node54
	node85--> |"id"| node51
	node85--> |"factor"| node49
	node85--> |"false"| node48
	node85--> |"num"| node53
	node85--> |"!"| node47
	node85--> |"("| node46
	node85--> |"term"| node52
	node85--> |"true"| node50
	node85--> |"rel"| node107
	node85--> |"-"| node45
	node85--> |"unary"| node44
	node85--> |"expr"| node57
	node86("<div>I86:<br>factor → ·false <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>factor → ·true <br>equality → equality != ·rel <br>expr → ·expr - term <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br></div>")
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
	node86--> |"expr"| node57
	node87("<div>I87:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>term → ·term * unary <br>join → join && ·equality <br>equality → ·rel <br>equality → ·equality == rel <br>equality → ·equality != rel <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br></div>")
	node87--> |"{"| node54
	node87--> |"expr"| node57
	node87--> |"equality"| node109
	node87--> |"unary"| node44
	node87--> |"-"| node45
	node87--> |"true"| node50
	node87--> |"rel"| node61
	node87--> |"term"| node52
	node87--> |"("| node46
	node87--> |"num"| node53
	node87--> |"!"| node47
	node87--> |"false"| node48
	node87--> |"factor"| node49
	node87--> |"id"| node51
	node88("<div>I88:<br>block_tail → ·else if ( bool stmt_or_block block_tail <br>block_tail → ·else stmt_or_block <br>block_tail → ·else if ( bool ) stmt_or_block block_tail <br>block_tail → ε ·<br>if_stmt → if ( bool stmt_or_block ·block_tail <br></div>")
	node88--> |"else"| node111
	node88--> |"block_tail"| node110
	node89("<div>I89:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>if_stmt → ·if ( bool stmt_or_block block_tail <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool stmt_or_block <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ id ] = expr ; <br>array_assignment → ·id [ num ] = expr ; <br>declaration → ·array_declaration ; <br>break_stmt → ·break ; <br>if_stmt → if ( bool ) ·stmt_or_block block_tail <br>stmt → ·array_assignment <br>block → ·{ declarations stmts } <br>stmt_or_block → ·stmt <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>declaration → ·basics id ; <br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·while_loop <br>stmt_or_block → ·block <br>block → ·{ declarations stmts <br>stmt → ·if_stmt <br></div>")
	node89--> |"{"| node11
	node89--> |"while"| node28
	node89--> |"id"| node27
	node89--> |"if"| node29
	node89--> |"assignment"| node19
	node89--> |"int"| node6
	node89--> |"block"| node82
	node89--> |"basics"| node13
	node89--> |"if_stmt"| node20
	node89--> |"float"| node4
	node89--> |"stmt_or_block"| node112
	node89--> |"while_loop"| node22
	node89--> |"array_assignment"| node30
	node89--> |"void"| node5
	node89--> |"declaration"| node21
	node89--> |"break_stmt"| node23
	node89--> |"array_declaration"| node16
	node89--> |"stmt"| node83
	node89--> |"break"| node25
	node90("<div>I90:<br>array_declaration → basics id [ id ] = ·{ array_init } <br></div>")
	node90--> |"{"| node113
	node91("<div>I91:<br>array_declaration → basics id [ num ] = ·{ array_init } <br></div>")
	node91--> |"{"| node114
	node92("<div>I92:<br>term → term ·/ unary <br>term → term ·* unary <br>expr → expr + term ·<br></div>")
	node92--> |"*"| node73
	node92--> |"/"| node72
	node93("<div>I93:<br>term → term ·/ unary <br>term → term ·* unary <br>expr → expr - term ·<br></div>")
	node93--> |"*"| node73
	node93--> |"/"| node72
	node94("<div>I94:<br>factor → ( expr ) ·<br></div>")
	node95("<div>I95:<br>factor → id [ id ·] <br>factor → id [ id ·] <br></div>")
	node95--> |"]"| node115
	node96("<div>I96:<br>factor → id [ num ·] <br>factor → id [ num ·<br></div>")
	node96--> |"]"| node116
	node97("<div>I97:<br>term → term / unary ·<br></div>")
	node98("<div>I98:<br>term → term * unary ·<br></div>")
	node99("<div>I99:<br>expr → { expr } ·<br></div>")
	node100("<div>I100:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr <br>expr → ·{ expr } <br>array_assignment → id [ id ] = ·expr ; <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br></div>")
	node100--> |"{"| node54
	node100--> |"term"| node52
	node100--> |"true"| node50
	node100--> |"id"| node51
	node100--> |"factor"| node49
	node100--> |"false"| node48
	node100--> |"num"| node53
	node100--> |"!"| node47
	node100--> |"("| node46
	node100--> |"-"| node45
	node100--> |"unary"| node44
	node100--> |"expr"| node117
	node101("<div>I101:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>array_assignment → id [ num ] = ·expr ; <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr <br></div>")
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
	node102("<div>I102:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr < expr ·<br></div>")
	node102--> |"-"| node66
	node102--> |"+"| node65
	node103("<div>I103:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr <= expr ·<br></div>")
	node103--> |"-"| node66
	node103--> |"+"| node65
	node104("<div>I104:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr > expr ·<br></div>")
	node104--> |"-"| node66
	node104--> |"+"| node65
	node105("<div>I105:<br>expr → expr ·+ term <br>expr → expr ·- term <br>rel → expr >= expr ·<br></div>")
	node105--> |"-"| node66
	node105--> |"+"| node65
	node106("<div>I106:<br>while_loop → while ( bool ) stmt_or_block ·<br></div>")
	node107("<div>I107:<br>equality → equality == rel ·<br></div>")
	node108("<div>I108:<br>equality → equality != rel ·<br></div>")
	node109("<div>I109:<br>equality → equality ·!= rel <br>equality → equality ·== rel <br>join → join && equality ·<br></div>")
	node109--> |"!="| node86
	node109--> |"=="| node85
	node110("<div>I110:<br>if_stmt → if ( bool stmt_or_block block_tail ·<br></div>")
	node111("<div>I111:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·void <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool stmt_or_block block_tail <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool stmt_or_block <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ id ] = expr ; <br>array_assignment → ·id [ num ] = expr ; <br>assignment → ·id = expr ; <br>declaration → ·array_declaration ; <br>block_tail → else ·if ( bool stmt_or_block block_tail <br>basics → ·int <br>block_tail → else ·stmt_or_block <br>declaration → ·basics id ; <br>block_tail → else ·if ( bool ) stmt_or_block block_tail <br>stmt → ·break_stmt <br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt_or_block → ·stmt <br>block → ·{ declarations stmts } <br>stmt → ·while_loop <br>stmt_or_block → ·block <br>block → ·{ declarations stmts <br>stmt → ·if_stmt <br></div>")
	node111--> |"{"| node11
	node111--> |"while"| node28
	node111--> |"id"| node27
	node111--> |"if"| node120
	node111--> |"assignment"| node19
	node111--> |"int"| node6
	node111--> |"block"| node82
	node111--> |"basics"| node13
	node111--> |"if_stmt"| node20
	node111--> |"float"| node4
	node111--> |"stmt_or_block"| node119
	node111--> |"while_loop"| node22
	node111--> |"array_assignment"| node30
	node111--> |"void"| node5
	node111--> |"declaration"| node21
	node111--> |"break_stmt"| node23
	node111--> |"array_declaration"| node16
	node111--> |"stmt"| node83
	node111--> |"break"| node25
	node112("<div>I112:<br>block_tail → ·else if ( bool stmt_or_block block_tail <br>block_tail → ·else stmt_or_block <br>block_tail → ·else if ( bool ) stmt_or_block block_tail <br>block_tail → ε ·<br>if_stmt → if ( bool ) stmt_or_block ·block_tail <br></div>")
	node112--> |"else"| node111
	node112--> |"block_tail"| node121
	node113("<div>I113:<br>array_init → ·id <br>array_init → ·array_init , id <br>array_init → ·num <br>array_init → ·array_init , num <br>array_declaration → basics id [ id ] = { ·array_init } <br></div>")
	node113--> |"num"| node124
	node113--> |"id"| node123
	node113--> |"array_init"| node122
	node114("<div>I114:<br>array_init → ·id <br>array_init → ·array_init , id <br>array_init → ·num <br>array_init → ·array_init , num <br>array_declaration → basics id [ num ] = { ·array_init } <br></div>")
	node114--> |"num"| node124
	node114--> |"id"| node123
	node114--> |"array_init"| node125
	node115("<div>I115:<br>factor → id [ id ] ·<br>factor → id [ id ] ·<br></div>")
	node116("<div>I116:<br>factor → id [ num ] ·<br></div>")
	node117("<div>I117:<br>expr → expr ·- term <br>expr → expr ·+ term <br>array_assignment → id [ id ] = expr ·; <br></div>")
	node117--> |";"| node126
	node117--> |"-"| node66
	node117--> |"+"| node65
	node118("<div>I118:<br>expr → expr ·+ term <br>expr → expr ·- term <br>array_assignment → id [ num ] = expr ·; <br></div>")
	node118--> |";"| node127
	node118--> |"-"| node66
	node118--> |"+"| node65
	node119("<div>I119:<br>block_tail → else stmt_or_block ·<br></div>")
	node120("<div>I120:<br>block_tail → else if ·( bool ) stmt_or_block block_tail <br>block_tail → else if ·( bool stmt_or_block block_tail <br>if_stmt → if ·( bool ) stmt_or_block block_tail <br>if_stmt → if ·( bool stmt_or_block block_tail <br></div>")
	node120--> |"("| node128
	node121("<div>I121:<br>if_stmt → if ( bool ) stmt_or_block block_tail ·<br></div>")
	node122("<div>I122:<br>array_declaration → basics id [ id ] = { array_init ·} <br>array_init → array_init ·, num <br>array_init → array_init ·, id <br></div>")
	node122--> |","| node130
	node122--> |"}"| node129
	node123("<div>I123:<br>array_init → id ·<br></div>")
	node124("<div>I124:<br>array_init → num ·<br></div>")
	node125("<div>I125:<br>array_declaration → basics id [ num ] = { array_init ·} <br>array_init → array_init ·, num <br>array_init → array_init ·, id <br></div>")
	node125--> |","| node130
	node125--> |"}"| node131
	node126("<div>I126:<br>array_assignment → id [ id ] = expr ; ·<br></div>")
	node127("<div>I127:<br>array_assignment → id [ num ] = expr ; ·<br></div>")
	node128("<div>I128:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ id ] <br>factor → ·id [ id ] <br>factor → ·id [ num <br>rel → ·expr > expr <br>rel → ·expr <= expr <br>equality → ·equality != rel <br>equality → ·equality == rel <br>join → ·equality <br>join → ·join && equality <br>bool → ·join <br>if_stmt → if ( ·bool stmt_or_block block_tail <br>if_stmt → if ( ·bool ) stmt_or_block block_tail <br>rel → ·expr < expr <br>block_tail → else if ( ·bool stmt_or_block block_tail <br>factor → ·( expr <br>equality → ·rel <br>block_tail → else if ( ·bool ) stmt_or_block block_tail <br>factor → ·( expr ) <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·{ expr } <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·id <br>factor → ·id [ num ] <br></div>")
	node128--> |"{"| node54
	node128--> |"num"| node53
	node128--> |"expr"| node57
	node128--> |"equality"| node59
	node128--> |"unary"| node44
	node128--> |"-"| node45
	node128--> |"join"| node60
	node128--> |"term"| node52
	node128--> |"bool"| node132
	node128--> |"rel"| node61
	node128--> |"true"| node50
	node128--> |"("| node46
	node128--> |"!"| node47
	node128--> |"false"| node48
	node128--> |"factor"| node49
	node128--> |"id"| node51
	node129("<div>I129:<br>array_declaration → basics id [ id ] = { array_init } ·<br></div>")
	node130("<div>I130:<br>array_init → array_init , ·id <br>array_init → array_init , ·num <br></div>")
	node130--> |"num"| node134
	node130--> |"id"| node133
	node131("<div>I131:<br>array_declaration → basics id [ num ] = { array_init } ·<br></div>")
	node132("<div>I132:<br>array_declaration → ·basics id [ id ] = { array_init } <br>stmt → ·if_stmt <br>block_tail → else if ( bool ·stmt_or_block block_tail <br>stmt → ·while_loop <br>block_tail → else if ( bool ·) stmt_or_block block_tail <br>block → ·{ declarations stmts } <br>stmt_or_block → ·stmt <br>stmt → ·array_assignment <br>stmt → ·declaration <br>stmt → ·assignment <br>stmt → ·break_stmt <br>stmt_or_block → ·block <br>block → ·{ declarations stmts <br>if_stmt → if ( bool ·) stmt_or_block block_tail <br>declaration → ·basics id ; <br>if_stmt → if ( bool ·stmt_or_block block_tail <br>declaration → ·array_declaration ; <br>assignment → ·id = expr ; <br>array_assignment → ·id [ num ] = expr ; <br>array_assignment → ·id [ id ] = expr ; <br>while_loop → ·while ( bool ) stmt_or_block <br>while_loop → ·while ( bool stmt_or_block <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>if_stmt → ·if ( bool stmt_or_block block_tail <br>break_stmt → ·break ; <br>basics → ·void <br>basics → ·int <br>basics → ·float <br>array_declaration → ·basics id [ num ] <br>array_declaration → ·basics id [ num ] = { array_init } <br></div>")
	node132--> |"{"| node11
	node132--> |"while"| node28
	node132--> |")"| node136
	node132--> |"id"| node27
	node132--> |"if"| node29
	node132--> |"assignment"| node19
	node132--> |"int"| node6
	node132--> |"block"| node82
	node132--> |"basics"| node13
	node132--> |"if_stmt"| node20
	node132--> |"float"| node4
	node132--> |"stmt_or_block"| node135
	node132--> |"while_loop"| node22
	node132--> |"array_assignment"| node30
	node132--> |"void"| node5
	node132--> |"declaration"| node21
	node132--> |"break_stmt"| node23
	node132--> |"array_declaration"| node16
	node132--> |"stmt"| node83
	node132--> |"break"| node25
	node133("<div>I133:<br>array_init → array_init , id ·<br></div>")
	node134("<div>I134:<br>array_init → array_init , num ·<br></div>")
	node135("<div>I135:<br>block_tail → ·else if ( bool stmt_or_block block_tail <br>block_tail → ·else stmt_or_block <br>block_tail → ·else if ( bool ) stmt_or_block block_tail <br>block_tail → ε ·<br>if_stmt → if ( bool stmt_or_block ·block_tail <br>block_tail → else if ( bool stmt_or_block ·block_tail <br></div>")
	node135--> |"else"| node111
	node135--> |"block_tail"| node137
	node136("<div>I136:<br>array_declaration → ·basics id [ id ] = { array_init } <br>array_declaration → ·basics id [ num ] = { array_init } <br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>if_stmt → ·if ( bool stmt_or_block block_tail <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool stmt_or_block <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ id ] = expr ; <br>array_assignment → ·id [ num ] = expr ; <br>declaration → ·array_declaration ; <br>declaration → ·basics id ; <br>stmt → ·if_stmt <br>break_stmt → ·break ; <br>if_stmt → if ( bool ) ·stmt_or_block block_tail <br>stmt → ·array_assignment <br>block → ·{ declarations stmts } <br>stmt_or_block → ·stmt <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>stmt → ·assignment <br>block_tail → else if ( bool ) ·stmt_or_block block_tail <br>stmt → ·declaration <br>stmt → ·while_loop <br>stmt_or_block → ·block <br>block → ·{ declarations stmts <br></div>")
	node136--> |"{"| node11
	node136--> |"while"| node28
	node136--> |"id"| node27
	node136--> |"if"| node29
	node136--> |"assignment"| node19
	node136--> |"int"| node6
	node136--> |"block"| node82
	node136--> |"basics"| node13
	node136--> |"if_stmt"| node20
	node136--> |"float"| node4
	node136--> |"stmt_or_block"| node138
	node136--> |"while_loop"| node22
	node136--> |"array_assignment"| node30
	node136--> |"void"| node5
	node136--> |"declaration"| node21
	node136--> |"break_stmt"| node23
	node136--> |"array_declaration"| node16
	node136--> |"stmt"| node83
	node136--> |"break"| node25
	node137("<div>I137:<br>block_tail → else if ( bool stmt_or_block block_tail ·<br>if_stmt → if ( bool stmt_or_block block_tail ·<br></div>")
	node138("<div>I138:<br>block_tail → ·else if ( bool stmt_or_block block_tail <br>block_tail → ·else stmt_or_block <br>block_tail → ·else if ( bool ) stmt_or_block block_tail <br>block_tail → ε ·<br>block_tail → else if ( bool ) stmt_or_block ·block_tail <br>if_stmt → if ( bool ) stmt_or_block ·block_tail <br></div>")
	node138--> |"else"| node111
	node138--> |"block_tail"| node139
	node139("<div>I139:<br>if_stmt → if ( bool ) stmt_or_block block_tail ·<br>block_tail → else if ( bool ) stmt_or_block block_tail ·<br></div>")
```
