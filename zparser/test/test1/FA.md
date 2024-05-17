## 产生式

- S → program 
- program → basics id ( ) block 
- block → { declarations stmts } 
- declarations → declaration declarations 
- declarations → ε 
- declaration → basics id ; 
- declaration → array_declaration ; 
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
- array_declaration → basics id [ num ] 
- array_assignment → id [ num ] = expr ; 
- while_loop → while ( bool ) stmt_or_block 
- stmt_or_block → stmt 
- stmt_or_block → block 
- if_stmt → if ( bool ) stmt_or_block block_tail 
- block_tail → ε 
- block_tail → else stmt_or_block 
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
- factor → num 
- factor → true 
- factor → false 
- break_stmt → break ; 
- START → S 

## FA Graph

```mermaid
	graph LR
	node0("<div>I0:<br>basics → ·float <br>basics → ·int <br>S → ·program <br>program → ·basics id ( ) block <br>START → ·S <br></div>")
	node0--> |"float"| node5
	node0--> |"int"| node4
	node0--> |"program"| node3
	node0--> |"S"| node2
	node0--> |"basics"| node1
	node1("<div>I1:<br>program → basics ·id ( ) block <br></div>")
	node1--> |"id"| node6
	node2("<div>I2:<br>START → S ·<br></div>")
	node3("<div>I3:<br>S → program ·<br></div>")
	node4("<div>I4:<br>basics → int ·<br></div>")
	node5("<div>I5:<br>basics → float ·<br></div>")
	node6("<div>I6:<br>program → basics id ·( ) block <br></div>")
	node6--> |"("| node7
	node7("<div>I7:<br>program → basics id ( ·) block <br></div>")
	node7--> |")"| node8
	node8("<div>I8:<br>block → ·{ declarations stmts } <br>program → basics id ( ) ·block <br></div>")
	node8--> |"block"| node10
	node8--> |"{"| node9
	node9("<div>I9:<br>basics → ·float <br>basics → ·int <br>array_declaration → ·basics id [ num ] <br>declaration → ·basics id ; <br>declaration → ·array_declaration ; <br>declarations → ε ·<br>declarations → ·declaration declarations <br>block → { ·declarations stmts } <br></div>")
	node9--> |"declarations"| node14
	node9--> |"declaration"| node13
	node9--> |"int"| node4
	node9--> |"float"| node5
	node9--> |"array_declaration"| node12
	node9--> |"basics"| node11
	node10("<div>I10:<br>program → basics id ( ) block ·<br></div>")
	node11("<div>I11:<br>declaration → basics ·id ; <br>array_declaration → basics ·id [ num ] <br></div>")
	node11--> |"id"| node15
	node12("<div>I12:<br>declaration → array_declaration ·; <br></div>")
	node12--> |";"| node16
	node13("<div>I13:<br>basics → ·float <br>basics → ·int <br>array_declaration → ·basics id [ num ] <br>declaration → ·basics id ; <br>declaration → ·array_declaration ; <br>declarations → ε ·<br>declarations → ·declaration declarations <br>declarations → declaration ·declarations <br></div>")
	node13--> |"declarations"| node17
	node13--> |"declaration"| node13
	node13--> |"int"| node4
	node13--> |"float"| node5
	node13--> |"array_declaration"| node12
	node13--> |"basics"| node11
	node14("<div>I14:<br>array_declaration → ·basics id [ num ] <br>basics → ·int <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool ) stmt_or_block <br>block → { declarations ·stmts } <br>declaration → ·array_declaration ; <br>array_assignment → ·id [ num ] = expr ; <br>stmts → ·stmt stmts <br>basics → ·float <br>stmts → ε ·<br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>stmt → ·if_stmt <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>declaration → ·basics id ; <br></div>")
	node14--> |"int"| node4
	node14--> |"float"| node5
	node14--> |"if_stmt"| node19
	node14--> |"basics"| node11
	node14--> |"assignment"| node18
	node14--> |"if"| node25
	node14--> |"stmts"| node26
	node14--> |"while_loop"| node20
	node14--> |"array_assignment"| node29
	node14--> |"declaration"| node28
	node14--> |"break_stmt"| node21
	node14--> |"id"| node27
	node14--> |"while"| node23
	node14--> |"stmt"| node22
	node14--> |"array_declaration"| node12
	node14--> |"break"| node24
	node15("<div>I15:<br>array_declaration → basics id ·[ num ] <br>declaration → basics id ·; <br></div>")
	node15--> |";"| node31
	node15--> |"["| node30
	node16("<div>I16:<br>declaration → array_declaration ; ·<br></div>")
	node17("<div>I17:<br>declarations → declaration declarations ·<br></div>")
	node18("<div>I18:<br>stmt → assignment ·<br></div>")
	node19("<div>I19:<br>stmt → if_stmt ·<br></div>")
	node20("<div>I20:<br>stmt → while_loop ·<br></div>")
	node21("<div>I21:<br>stmt → break_stmt ·<br></div>")
	node22("<div>I22:<br>array_declaration → ·basics id [ num ] <br>basics → ·int <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool ) stmt_or_block <br>stmts → stmt ·stmts <br>stmt → ·assignment <br>stmts → ·stmt stmts <br>basics → ·float <br>stmts → ε ·<br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>stmt → ·if_stmt <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>declaration → ·basics id ; <br>declaration → ·array_declaration ; <br>array_assignment → ·id [ num ] = expr ; <br></div>")
	node22--> |"int"| node4
	node22--> |"float"| node5
	node22--> |"if_stmt"| node19
	node22--> |"basics"| node11
	node22--> |"assignment"| node18
	node22--> |"if"| node25
	node22--> |"stmts"| node32
	node22--> |"while_loop"| node20
	node22--> |"array_assignment"| node29
	node22--> |"declaration"| node28
	node22--> |"break_stmt"| node21
	node22--> |"id"| node27
	node22--> |"while"| node23
	node22--> |"stmt"| node22
	node22--> |"array_declaration"| node12
	node22--> |"break"| node24
	node23("<div>I23:<br>while_loop → while ·( bool ) stmt_or_block <br></div>")
	node23--> |"("| node33
	node24("<div>I24:<br>break_stmt → break ·; <br></div>")
	node24--> |";"| node34
	node25("<div>I25:<br>if_stmt → if ·( bool ) stmt_or_block block_tail <br></div>")
	node25--> |"("| node35
	node26("<div>I26:<br>block → { declarations stmts ·} <br></div>")
	node26--> |"}"| node36
	node27("<div>I27:<br>assignment → id ·= expr ; <br>array_assignment → id ·[ num ] = expr ; <br></div>")
	node27--> |"["| node38
	node27--> |"="| node37
	node28("<div>I28:<br>stmt → declaration ·<br></div>")
	node29("<div>I29:<br>stmt → array_assignment ·<br></div>")
	node30("<div>I30:<br>array_declaration → basics id [ ·num ] <br></div>")
	node30--> |"num"| node39
	node31("<div>I31:<br>declaration → basics id ; ·<br></div>")
	node32("<div>I32:<br>stmts → stmt stmts ·<br></div>")
	node33("<div>I33:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>term → ·term * unary <br>expr → ·term <br>expr → ·expr - term <br>unary → ·factor <br>while_loop → while ( ·bool ) stmt_or_block <br>equality → ·equality == rel <br>bool → ·join <br>join → ·join && equality <br>join → ·equality <br>equality → ·equality != rel <br>equality → ·rel <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·expr + term <br></div>")
	node33--> |"true"| node54
	node33--> |"expr"| node40
	node33--> |"bool"| node41
	node33--> |"rel"| node42
	node33--> |"term"| node50
	node33--> |"equality"| node43
	node33--> |"unary"| node44
	node33--> |"-"| node48
	node33--> |"("| node46
	node33--> |"num"| node47
	node33--> |"join"| node49
	node33--> |"!"| node45
	node33--> |"false"| node51
	node33--> |"id"| node53
	node33--> |"factor"| node52
	node34("<div>I34:<br>break_stmt → break ; ·<br></div>")
	node35("<div>I35:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>term → ·term * unary <br>expr → ·term <br>expr → ·expr - term <br>factor → ·id [ num ] <br>if_stmt → if ( ·bool ) stmt_or_block block_tail <br>rel → ·expr < expr <br>bool → ·join <br>join → ·join && equality <br>join → ·equality <br>equality → ·equality == rel <br>equality → ·equality != rel <br>equality → ·rel <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·expr + term <br></div>")
	node35--> |"true"| node54
	node35--> |"expr"| node40
	node35--> |"bool"| node55
	node35--> |"rel"| node42
	node35--> |"term"| node50
	node35--> |"equality"| node43
	node35--> |"unary"| node44
	node35--> |"-"| node48
	node35--> |"("| node46
	node35--> |"num"| node47
	node35--> |"join"| node49
	node35--> |"!"| node45
	node35--> |"false"| node51
	node35--> |"id"| node53
	node35--> |"factor"| node52
	node36("<div>I36:<br>block → { declarations stmts } ·<br></div>")
	node37("<div>I37:<br>factor → ·false <br>factor → ·num <br>factor → ·true <br>assignment → id = ·expr ; <br>factor → ·id <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id [ num ] <br></div>")
	node37--> |"id"| node53
	node37--> |"factor"| node52
	node37--> |"false"| node51
	node37--> |"true"| node54
	node37--> |"term"| node50
	node37--> |"num"| node47
	node37--> |"("| node46
	node37--> |"!"| node45
	node37--> |"-"| node48
	node37--> |"unary"| node44
	node37--> |"expr"| node56
	node38("<div>I38:<br>array_assignment → id [ ·num ] = expr ; <br></div>")
	node38--> |"num"| node57
	node39("<div>I39:<br>array_declaration → basics id [ num ·] <br></div>")
	node39--> |"]"| node58
	node40("<div>I40:<br>expr → expr ·+ term <br>rel → expr ·<br>rel → expr ·>= expr <br>rel → expr ·> expr <br>rel → expr ·<= expr <br>rel → expr ·< expr <br>expr → expr ·- term <br></div>")
	node40--> |">="| node63
	node40--> |"+"| node64
	node40--> |"<"| node62
	node40--> |"<="| node61
	node40--> |">"| node60
	node40--> |"-"| node59
	node41("<div>I41:<br>while_loop → while ( bool ·) stmt_or_block <br></div>")
	node41--> |")"| node65
	node42("<div>I42:<br>equality → rel ·<br></div>")
	node43("<div>I43:<br>equality → equality ·!= rel <br>join → equality ·<br>equality → equality ·== rel <br></div>")
	node43--> |"!="| node67
	node43--> |"=="| node66
	node44("<div>I44:<br>term → unary ·<br></div>")
	node45("<div>I45:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>unary → ! ·unary <br></div>")
	node45--> |"true"| node54
	node45--> |"id"| node53
	node45--> |"factor"| node52
	node45--> |"false"| node51
	node45--> |"num"| node47
	node45--> |"("| node46
	node45--> |"!"| node45
	node45--> |"-"| node48
	node45--> |"unary"| node68
	node46("<div>I46:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ( ·expr ) <br>unary → ·- unary <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br></div>")
	node46--> |"id"| node53
	node46--> |"factor"| node52
	node46--> |"false"| node51
	node46--> |"true"| node54
	node46--> |"term"| node50
	node46--> |"num"| node47
	node46--> |"("| node46
	node46--> |"!"| node45
	node46--> |"-"| node48
	node46--> |"unary"| node44
	node46--> |"expr"| node69
	node47("<div>I47:<br>factor → num ·<br></div>")
	node48("<div>I48:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>factor → ·( expr ) <br>unary → - ·unary <br></div>")
	node48--> |"true"| node54
	node48--> |"id"| node53
	node48--> |"factor"| node52
	node48--> |"false"| node51
	node48--> |"num"| node47
	node48--> |"("| node46
	node48--> |"!"| node45
	node48--> |"-"| node48
	node48--> |"unary"| node70
	node49("<div>I49:<br>join → join ·&& equality <br>bool → join ·<br></div>")
	node49--> |"&&"| node71
	node50("<div>I50:<br>expr → term ·<br>term → term ·* unary <br>term → term ·/ unary <br></div>")
	node50--> |"*"| node73
	node50--> |"/"| node72
	node51("<div>I51:<br>factor → false ·<br></div>")
	node52("<div>I52:<br>unary → factor ·<br></div>")
	node53("<div>I53:<br>factor → id ·<br>factor → id ·[ num ] <br></div>")
	node53--> |"["| node74
	node54("<div>I54:<br>factor → true ·<br></div>")
	node55("<div>I55:<br>if_stmt → if ( bool ·) stmt_or_block block_tail <br></div>")
	node55--> |")"| node75
	node56("<div>I56:<br>expr → expr ·+ term <br>expr → expr ·- term <br>assignment → id = expr ·; <br></div>")
	node56--> |"+"| node64
	node56--> |";"| node76
	node56--> |"-"| node59
	node57("<div>I57:<br>array_assignment → id [ num ·] = expr ; <br></div>")
	node57--> |"]"| node77
	node58("<div>I58:<br>array_declaration → basics id [ num ] ·<br></div>")
	node59("<div>I59:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>term → ·term * unary <br>factor → ·id <br>expr → expr - ·term <br></div>")
	node59--> |"id"| node53
	node59--> |"factor"| node52
	node59--> |"false"| node51
	node59--> |"true"| node54
	node59--> |"term"| node78
	node59--> |"num"| node47
	node59--> |"("| node46
	node59--> |"!"| node45
	node59--> |"-"| node48
	node59--> |"unary"| node44
	node60("<div>I60:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>rel → expr > ·expr <br>expr → ·expr - term <br>expr → ·expr + term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br></div>")
	node60--> |"id"| node53
	node60--> |"factor"| node52
	node60--> |"false"| node51
	node60--> |"true"| node54
	node60--> |"term"| node50
	node60--> |"num"| node47
	node60--> |"("| node46
	node60--> |"!"| node45
	node60--> |"-"| node48
	node60--> |"unary"| node44
	node60--> |"expr"| node79
	node61("<div>I61:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>rel → expr <= ·expr <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br></div>")
	node61--> |"id"| node53
	node61--> |"factor"| node52
	node61--> |"false"| node51
	node61--> |"true"| node54
	node61--> |"term"| node50
	node61--> |"num"| node47
	node61--> |"("| node46
	node61--> |"!"| node45
	node61--> |"-"| node48
	node61--> |"unary"| node44
	node61--> |"expr"| node80
	node62("<div>I62:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>rel → expr < ·expr <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br></div>")
	node62--> |"id"| node53
	node62--> |"factor"| node52
	node62--> |"false"| node51
	node62--> |"true"| node54
	node62--> |"term"| node50
	node62--> |"num"| node47
	node62--> |"("| node46
	node62--> |"!"| node45
	node62--> |"-"| node48
	node62--> |"unary"| node44
	node62--> |"expr"| node81
	node63("<div>I63:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>rel → expr >= ·expr <br>expr → ·term <br>expr → ·expr + term <br>expr → ·expr - term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br></div>")
	node63--> |"id"| node53
	node63--> |"factor"| node52
	node63--> |"false"| node51
	node63--> |"true"| node54
	node63--> |"term"| node50
	node63--> |"num"| node47
	node63--> |"("| node46
	node63--> |"!"| node45
	node63--> |"-"| node48
	node63--> |"unary"| node44
	node63--> |"expr"| node82
	node64("<div>I64:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>term → ·term * unary <br>factor → ·( expr ) <br>expr → expr + ·term <br></div>")
	node64--> |"id"| node53
	node64--> |"factor"| node52
	node64--> |"false"| node51
	node64--> |"true"| node54
	node64--> |"term"| node83
	node64--> |"num"| node47
	node64--> |"("| node46
	node64--> |"!"| node45
	node64--> |"-"| node48
	node64--> |"unary"| node44
	node65("<div>I65:<br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ num ] = expr ; <br>while_loop → while ( bool ) ·stmt_or_block <br>stmt → ·if_stmt <br>block → ·{ declarations stmts } <br>stmt_or_block → ·stmt <br>stmt_or_block → ·block <br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>declaration → ·basics id ; <br>declaration → ·array_declaration ; <br></div>")
	node65--> |"block"| node86
	node65--> |"id"| node27
	node65--> |"int"| node4
	node65--> |"float"| node5
	node65--> |"if_stmt"| node19
	node65--> |"basics"| node11
	node65--> |"{"| node9
	node65--> |"assignment"| node18
	node65--> |"if"| node25
	node65--> |"stmt_or_block"| node84
	node65--> |"while_loop"| node20
	node65--> |"array_assignment"| node29
	node65--> |"declaration"| node28
	node65--> |"break_stmt"| node21
	node65--> |"while"| node23
	node65--> |"stmt"| node85
	node65--> |"array_declaration"| node12
	node65--> |"break"| node24
	node66("<div>I66:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>equality → equality == ·rel <br>expr → ·expr - term <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·expr + term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br></div>")
	node66--> |"id"| node53
	node66--> |"factor"| node52
	node66--> |"false"| node51
	node66--> |"num"| node47
	node66--> |"("| node46
	node66--> |"!"| node45
	node66--> |"-"| node48
	node66--> |"unary"| node44
	node66--> |"true"| node54
	node66--> |"term"| node50
	node66--> |"rel"| node87
	node66--> |"expr"| node40
	node67("<div>I67:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>equality → equality != ·rel <br>expr → ·term <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·expr + term <br>expr → ·expr - term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br></div>")
	node67--> |"id"| node53
	node67--> |"factor"| node52
	node67--> |"false"| node51
	node67--> |"num"| node47
	node67--> |"("| node46
	node67--> |"!"| node45
	node67--> |"-"| node48
	node67--> |"unary"| node44
	node67--> |"true"| node54
	node67--> |"term"| node50
	node67--> |"rel"| node88
	node67--> |"expr"| node40
	node68("<div>I68:<br>unary → ! unary ·<br></div>")
	node69("<div>I69:<br>expr → expr ·- term <br>expr → expr ·+ term <br>factor → ( expr ·) <br></div>")
	node69--> |"+"| node64
	node69--> |"-"| node59
	node69--> |")"| node89
	node70("<div>I70:<br>unary → - unary ·<br></div>")
	node71("<div>I71:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>join → join && ·equality <br>equality → ·rel <br>equality → ·equality == rel <br>equality → ·equality != rel <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br></div>")
	node71--> |"id"| node53
	node71--> |"factor"| node52
	node71--> |"false"| node51
	node71--> |"num"| node47
	node71--> |"("| node46
	node71--> |"!"| node45
	node71--> |"-"| node48
	node71--> |"unary"| node44
	node71--> |"equality"| node90
	node71--> |"true"| node54
	node71--> |"term"| node50
	node71--> |"rel"| node42
	node71--> |"expr"| node40
	node72("<div>I72:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·- unary <br>unary → ·! unary <br>unary → ·factor <br>term → term / ·unary <br></div>")
	node72--> |"true"| node54
	node72--> |"id"| node53
	node72--> |"factor"| node52
	node72--> |"false"| node51
	node72--> |"num"| node47
	node72--> |"("| node46
	node72--> |"!"| node45
	node72--> |"-"| node48
	node72--> |"unary"| node91
	node73("<div>I73:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·! unary <br>unary → ·- unary <br>term → term * ·unary <br></div>")
	node73--> |"true"| node54
	node73--> |"id"| node53
	node73--> |"factor"| node52
	node73--> |"false"| node51
	node73--> |"num"| node47
	node73--> |"("| node46
	node73--> |"!"| node45
	node73--> |"-"| node48
	node73--> |"unary"| node92
	node74("<div>I74:<br>factor → id [ ·num ] <br></div>")
	node74--> |"num"| node93
	node75("<div>I75:<br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ num ] = expr ; <br>declaration → ·basics id ; <br>stmt_or_block → ·stmt <br>stmt_or_block → ·block <br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>stmt → ·if_stmt <br>if_stmt → if ( bool ) ·stmt_or_block block_tail <br>block → ·{ declarations stmts } <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>declaration → ·array_declaration ; <br></div>")
	node75--> |"block"| node86
	node75--> |"id"| node27
	node75--> |"int"| node4
	node75--> |"float"| node5
	node75--> |"if_stmt"| node19
	node75--> |"basics"| node11
	node75--> |"{"| node9
	node75--> |"assignment"| node18
	node75--> |"if"| node25
	node75--> |"stmt_or_block"| node94
	node75--> |"while_loop"| node20
	node75--> |"array_assignment"| node29
	node75--> |"declaration"| node28
	node75--> |"break_stmt"| node21
	node75--> |"while"| node23
	node75--> |"stmt"| node85
	node75--> |"array_declaration"| node12
	node75--> |"break"| node24
	node76("<div>I76:<br>assignment → id = expr ; ·<br></div>")
	node77("<div>I77:<br>array_assignment → id [ num ] ·= expr ; <br></div>")
	node77--> |"="| node95
	node78("<div>I78:<br>expr → expr - term ·<br>term → term ·* unary <br>term → term ·/ unary <br></div>")
	node78--> |"*"| node73
	node78--> |"/"| node72
	node79("<div>I79:<br>expr → expr ·+ term <br>expr → expr ·- term <br>rel → expr > expr ·<br></div>")
	node79--> |"+"| node64
	node79--> |"-"| node59
	node80("<div>I80:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr <= expr ·<br></div>")
	node80--> |"+"| node64
	node80--> |"-"| node59
	node81("<div>I81:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr < expr ·<br></div>")
	node81--> |"+"| node64
	node81--> |"-"| node59
	node82("<div>I82:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr >= expr ·<br></div>")
	node82--> |"+"| node64
	node82--> |"-"| node59
	node83("<div>I83:<br>expr → expr + term ·<br>term → term ·* unary <br>term → term ·/ unary <br></div>")
	node83--> |"*"| node73
	node83--> |"/"| node72
	node84("<div>I84:<br>while_loop → while ( bool ) stmt_or_block ·<br></div>")
	node85("<div>I85:<br>stmt_or_block → stmt ·<br></div>")
	node86("<div>I86:<br>stmt_or_block → block ·<br></div>")
	node87("<div>I87:<br>equality → equality == rel ·<br></div>")
	node88("<div>I88:<br>equality → equality != rel ·<br></div>")
	node89("<div>I89:<br>factor → ( expr ) ·<br></div>")
	node90("<div>I90:<br>equality → equality ·!= rel <br>equality → equality ·== rel <br>join → join && equality ·<br></div>")
	node90--> |"!="| node67
	node90--> |"=="| node66
	node91("<div>I91:<br>term → term / unary ·<br></div>")
	node92("<div>I92:<br>term → term * unary ·<br></div>")
	node93("<div>I93:<br>factor → id [ num ·] <br></div>")
	node93--> |"]"| node96
	node94("<div>I94:<br>block_tail → ·else stmt_or_block <br>block_tail → ε ·<br>if_stmt → if ( bool ) stmt_or_block ·block_tail <br></div>")
	node94--> |"else"| node98
	node94--> |"block_tail"| node97
	node95("<div>I95:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>array_assignment → id [ num ] = ·expr ; <br>expr → ·expr - term <br>expr → ·expr + term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br></div>")
	node95--> |"id"| node53
	node95--> |"factor"| node52
	node95--> |"false"| node51
	node95--> |"true"| node54
	node95--> |"term"| node50
	node95--> |"num"| node47
	node95--> |"("| node46
	node95--> |"!"| node45
	node95--> |"-"| node48
	node95--> |"unary"| node44
	node95--> |"expr"| node99
	node96("<div>I96:<br>factor → id [ num ] ·<br></div>")
	node97("<div>I97:<br>if_stmt → if ( bool ) stmt_or_block block_tail ·<br></div>")
	node98("<div>I98:<br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ num ] = expr ; <br>block_tail → else ·stmt_or_block <br>stmt → ·while_loop <br>stmt_or_block → ·stmt <br>stmt_or_block → ·block <br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt → ·if_stmt <br>block → ·{ declarations stmts } <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>declaration → ·basics id ; <br>declaration → ·array_declaration ; <br></div>")
	node98--> |"block"| node86
	node98--> |"id"| node27
	node98--> |"int"| node4
	node98--> |"float"| node5
	node98--> |"if_stmt"| node19
	node98--> |"basics"| node11
	node98--> |"{"| node9
	node98--> |"assignment"| node18
	node98--> |"if"| node25
	node98--> |"stmt_or_block"| node100
	node98--> |"while_loop"| node20
	node98--> |"array_assignment"| node29
	node98--> |"declaration"| node28
	node98--> |"break_stmt"| node21
	node98--> |"while"| node23
	node98--> |"stmt"| node85
	node98--> |"array_declaration"| node12
	node98--> |"break"| node24
	node99("<div>I99:<br>expr → expr ·+ term <br>expr → expr ·- term <br>array_assignment → id [ num ] = expr ·; <br></div>")
	node99--> |"+"| node64
	node99--> |";"| node101
	node99--> |"-"| node59
	node100("<div>I100:<br>block_tail → else stmt_or_block ·<br></div>")
	node101("<div>I101:<br>array_assignment → id [ num ] = expr ; ·<br></div>")
```
