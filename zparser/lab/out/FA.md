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
	node0("<div>I0:<br>basics → ·float <br>basics → ·int <br>basics → ·void <br>program → ·basics id ( ) block <br>S → ·program <br>START → ·S <br></div>")
	node0--> |"float"| node6
	node0--> |"int"| node5
	node0--> |"void"| node4
	node0--> |"program"| node3
	node0--> |"S"| node2
	node0--> |"basics"| node1
	node1("<div>I1:<br>program → basics ·id ( ) block <br></div>")
	node1--> |"id"| node7
	node2("<div>I2:<br>START → S ·<br></div>")
	node3("<div>I3:<br>S → program ·<br></div>")
	node4("<div>I4:<br>basics → void ·<br></div>")
	node5("<div>I5:<br>basics → int ·<br></div>")
	node6("<div>I6:<br>basics → float ·<br></div>")
	node7("<div>I7:<br>program → basics id ·( ) block <br></div>")
	node7--> |"("| node8
	node8("<div>I8:<br>program → basics id ( ·) block <br></div>")
	node8--> |")"| node9
	node9("<div>I9:<br>block → ·{ declarations stmts } <br>program → basics id ( ) ·block <br></div>")
	node9--> |"block"| node11
	node9--> |"{"| node10
	node10("<div>I10:<br>basics → ·float <br>basics → ·int <br>basics → ·void <br>declaration → ·basics id ; <br>array_declaration → ·basics id [ num ] <br>declaration → ·array_declaration ; <br>declarations → ε ·<br>declarations → ·declaration declarations <br>block → { ·declarations stmts } <br></div>")
	node10--> |"int"| node5
	node10--> |"void"| node4
	node10--> |"float"| node6
	node10--> |"array_declaration"| node15
	node10--> |"declarations"| node14
	node10--> |"declaration"| node13
	node10--> |"basics"| node12
	node11("<div>I11:<br>program → basics id ( ) block ·<br></div>")
	node12("<div>I12:<br>array_declaration → basics ·id [ num ] <br>declaration → basics ·id ; <br></div>")
	node12--> |"id"| node16
	node13("<div>I13:<br>basics → ·float <br>basics → ·int <br>basics → ·void <br>declaration → ·basics id ; <br>array_declaration → ·basics id [ num ] <br>declaration → ·array_declaration ; <br>declarations → ε ·<br>declarations → ·declaration declarations <br>declarations → declaration ·declarations <br></div>")
	node13--> |"int"| node5
	node13--> |"void"| node4
	node13--> |"float"| node6
	node13--> |"array_declaration"| node15
	node13--> |"declarations"| node17
	node13--> |"declaration"| node13
	node13--> |"basics"| node12
	node14("<div>I14:<br>array_declaration → ·basics id [ num ] <br>basics → ·int <br>basics → ·void <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool ) stmt_or_block <br>block → { declarations ·stmts } <br>declaration → ·array_declaration ; <br>stmts → ·stmt stmts <br>basics → ·float <br>stmts → ε ·<br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>stmt → ·if_stmt <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>declaration → ·basics id ; <br>array_assignment → ·id [ num ] = expr ; <br></div>")
	node14--> |"while"| node27
	node14--> |"if"| node28
	node14--> |"assignment"| node18
	node14--> |"int"| node5
	node14--> |"float"| node6
	node14--> |"if_stmt"| node19
	node14--> |"basics"| node12
	node14--> |"stmts"| node25
	node14--> |"while_loop"| node20
	node14--> |"id"| node26
	node14--> |"array_assignment"| node29
	node14--> |"void"| node4
	node14--> |"break_stmt"| node21
	node14--> |"declaration"| node23
	node14--> |"stmt"| node22
	node14--> |"array_declaration"| node15
	node14--> |"break"| node24
	node15("<div>I15:<br>declaration → array_declaration ·; <br></div>")
	node15--> |";"| node30
	node16("<div>I16:<br>declaration → basics id ·; <br>array_declaration → basics id ·[ num ] <br></div>")
	node16--> |";"| node32
	node16--> |"["| node31
	node17("<div>I17:<br>declarations → declaration declarations ·<br></div>")
	node18("<div>I18:<br>stmt → assignment ·<br></div>")
	node19("<div>I19:<br>stmt → if_stmt ·<br></div>")
	node20("<div>I20:<br>stmt → while_loop ·<br></div>")
	node21("<div>I21:<br>stmt → break_stmt ·<br></div>")
	node22("<div>I22:<br>array_declaration → ·basics id [ num ] <br>basics → ·void <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool ) stmt_or_block <br>basics → ·int <br>stmts → stmt ·stmts <br>stmts → ·stmt stmts <br>basics → ·float <br>stmts → ε ·<br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>stmt → ·if_stmt <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>declaration → ·basics id ; <br>declaration → ·array_declaration ; <br>array_assignment → ·id [ num ] = expr ; <br></div>")
	node22--> |"while"| node27
	node22--> |"if"| node28
	node22--> |"assignment"| node18
	node22--> |"int"| node5
	node22--> |"float"| node6
	node22--> |"if_stmt"| node19
	node22--> |"basics"| node12
	node22--> |"stmts"| node33
	node22--> |"while_loop"| node20
	node22--> |"id"| node26
	node22--> |"array_assignment"| node29
	node22--> |"void"| node4
	node22--> |"break_stmt"| node21
	node22--> |"declaration"| node23
	node22--> |"stmt"| node22
	node22--> |"array_declaration"| node15
	node22--> |"break"| node24
	node23("<div>I23:<br>stmt → declaration ·<br></div>")
	node24("<div>I24:<br>break_stmt → break ·; <br></div>")
	node24--> |";"| node34
	node25("<div>I25:<br>block → { declarations stmts ·} <br></div>")
	node25--> |"}"| node35
	node26("<div>I26:<br>array_assignment → id ·[ num ] = expr ; <br>assignment → id ·= expr ; <br></div>")
	node26--> |"["| node37
	node26--> |"="| node36
	node27("<div>I27:<br>while_loop → while ·( bool ) stmt_or_block <br></div>")
	node27--> |"("| node38
	node28("<div>I28:<br>if_stmt → if ·( bool ) stmt_or_block block_tail <br></div>")
	node28--> |"("| node39
	node29("<div>I29:<br>stmt → array_assignment ·<br></div>")
	node30("<div>I30:<br>declaration → array_declaration ; ·<br></div>")
	node31("<div>I31:<br>array_declaration → basics id [ ·num ] <br></div>")
	node31--> |"num"| node40
	node32("<div>I32:<br>declaration → basics id ; ·<br></div>")
	node33("<div>I33:<br>stmts → stmt stmts ·<br></div>")
	node34("<div>I34:<br>break_stmt → break ; ·<br></div>")
	node35("<div>I35:<br>block → { declarations stmts } ·<br></div>")
	node36("<div>I36:<br>factor → ·false <br>factor → ·num <br>factor → ·true <br>assignment → id = ·expr ; <br>factor → ·id <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id [ num ] <br></div>")
	node36--> |"term"| node51
	node36--> |"true"| node49
	node36--> |"id"| node50
	node36--> |"factor"| node48
	node36--> |"false"| node47
	node36--> |"num"| node45
	node36--> |"("| node44
	node36--> |"!"| node43
	node36--> |"-"| node46
	node36--> |"unary"| node42
	node36--> |"expr"| node41
	node37("<div>I37:<br>array_assignment → id [ ·num ] = expr ; <br></div>")
	node37--> |"num"| node52
	node38("<div>I38:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>term → ·term * unary <br>expr → ·term <br>expr → ·expr - term <br>unary → ·factor <br>while_loop → while ( ·bool ) stmt_or_block <br>equality → ·equality == rel <br>bool → ·join <br>join → ·join && equality <br>join → ·equality <br>equality → ·equality != rel <br>equality → ·rel <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·expr + term <br></div>")
	node38--> |"expr"| node53
	node38--> |"term"| node51
	node38--> |"bool"| node54
	node38--> |"rel"| node55
	node38--> |"true"| node49
	node38--> |"equality"| node56
	node38--> |"unary"| node42
	node38--> |"-"| node46
	node38--> |"("| node44
	node38--> |"num"| node45
	node38--> |"join"| node57
	node38--> |"!"| node43
	node38--> |"false"| node47
	node38--> |"id"| node50
	node38--> |"factor"| node48
	node39("<div>I39:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>term → ·term * unary <br>expr → ·term <br>expr → ·expr - term <br>if_stmt → if ( ·bool ) stmt_or_block block_tail <br>join → ·join && equality <br>bool → ·join <br>join → ·equality <br>equality → ·equality == rel <br>equality → ·equality != rel <br>equality → ·rel <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·expr + term <br></div>")
	node39--> |"expr"| node53
	node39--> |"term"| node51
	node39--> |"bool"| node58
	node39--> |"rel"| node55
	node39--> |"true"| node49
	node39--> |"equality"| node56
	node39--> |"unary"| node42
	node39--> |"-"| node46
	node39--> |"("| node44
	node39--> |"num"| node45
	node39--> |"join"| node57
	node39--> |"!"| node43
	node39--> |"false"| node47
	node39--> |"id"| node50
	node39--> |"factor"| node48
	node40("<div>I40:<br>array_declaration → basics id [ num ·] <br></div>")
	node40--> |"]"| node59
	node41("<div>I41:<br>expr → expr ·- term <br>expr → expr ·+ term <br>assignment → id = expr ·; <br></div>")
	node41--> |"+"| node62
	node41--> |";"| node61
	node41--> |"-"| node60
	node42("<div>I42:<br>term → unary ·<br></div>")
	node43("<div>I43:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·- unary <br>unary → ·! unary <br>unary → ·factor <br>unary → ! ·unary <br></div>")
	node43--> |"true"| node49
	node43--> |"id"| node50
	node43--> |"factor"| node48
	node43--> |"false"| node47
	node43--> |"num"| node45
	node43--> |"("| node44
	node43--> |"!"| node43
	node43--> |"-"| node46
	node43--> |"unary"| node63
	node44("<div>I44:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ( ·expr ) <br>unary → ·- unary <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br></div>")
	node44--> |"term"| node51
	node44--> |"true"| node49
	node44--> |"id"| node50
	node44--> |"factor"| node48
	node44--> |"false"| node47
	node44--> |"num"| node45
	node44--> |"("| node44
	node44--> |"!"| node43
	node44--> |"-"| node46
	node44--> |"unary"| node42
	node44--> |"expr"| node64
	node45("<div>I45:<br>factor → num ·<br></div>")
	node46("<div>I46:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>factor → ·( expr ) <br>unary → - ·unary <br></div>")
	node46--> |"true"| node49
	node46--> |"id"| node50
	node46--> |"factor"| node48
	node46--> |"false"| node47
	node46--> |"num"| node45
	node46--> |"("| node44
	node46--> |"!"| node43
	node46--> |"-"| node46
	node46--> |"unary"| node65
	node47("<div>I47:<br>factor → false ·<br></div>")
	node48("<div>I48:<br>unary → factor ·<br></div>")
	node49("<div>I49:<br>factor → true ·<br></div>")
	node50("<div>I50:<br>factor → id ·[ num ] <br>factor → id ·<br></div>")
	node50--> |"["| node66
	node51("<div>I51:<br>term → term ·/ unary <br>term → term ·* unary <br>expr → term ·<br></div>")
	node51--> |"*"| node68
	node51--> |"/"| node67
	node52("<div>I52:<br>array_assignment → id [ num ·] = expr ; <br></div>")
	node52--> |"]"| node69
	node53("<div>I53:<br>expr → expr ·+ term <br>rel → expr ·<br>rel → expr ·>= expr <br>rel → expr ·> expr <br>rel → expr ·<= expr <br>rel → expr ·< expr <br>expr → expr ·- term <br></div>")
	node53--> |">="| node73
	node53--> |"+"| node62
	node53--> |"<"| node72
	node53--> |">"| node71
	node53--> |"<="| node70
	node53--> |"-"| node60
	node54("<div>I54:<br>while_loop → while ( bool ·) stmt_or_block <br></div>")
	node54--> |")"| node74
	node55("<div>I55:<br>equality → rel ·<br></div>")
	node56("<div>I56:<br>equality → equality ·!= rel <br>join → equality ·<br>equality → equality ·== rel <br></div>")
	node56--> |"!="| node76
	node56--> |"=="| node75
	node57("<div>I57:<br>join → join ·&& equality <br>bool → join ·<br></div>")
	node57--> |"&&"| node77
	node58("<div>I58:<br>if_stmt → if ( bool ·) stmt_or_block block_tail <br></div>")
	node58--> |")"| node78
	node59("<div>I59:<br>array_declaration → basics id [ num ] ·<br></div>")
	node60("<div>I60:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>term → ·term * unary <br>factor → ·id <br>expr → expr - ·term <br></div>")
	node60--> |"term"| node79
	node60--> |"true"| node49
	node60--> |"id"| node50
	node60--> |"factor"| node48
	node60--> |"false"| node47
	node60--> |"num"| node45
	node60--> |"("| node44
	node60--> |"!"| node43
	node60--> |"-"| node46
	node60--> |"unary"| node42
	node61("<div>I61:<br>assignment → id = expr ; ·<br></div>")
	node62("<div>I62:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>term → ·term * unary <br>factor → ·( expr ) <br>expr → expr + ·term <br></div>")
	node62--> |"term"| node80
	node62--> |"true"| node49
	node62--> |"id"| node50
	node62--> |"factor"| node48
	node62--> |"false"| node47
	node62--> |"num"| node45
	node62--> |"("| node44
	node62--> |"!"| node43
	node62--> |"-"| node46
	node62--> |"unary"| node42
	node63("<div>I63:<br>unary → ! unary ·<br></div>")
	node64("<div>I64:<br>expr → expr ·- term <br>expr → expr ·+ term <br>factor → ( expr ·) <br></div>")
	node64--> |"+"| node62
	node64--> |"-"| node60
	node64--> |")"| node81
	node65("<div>I65:<br>unary → - unary ·<br></div>")
	node66("<div>I66:<br>factor → id [ ·num ] <br></div>")
	node66--> |"num"| node82
	node67("<div>I67:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·- unary <br>unary → ·! unary <br>unary → ·factor <br>term → term / ·unary <br></div>")
	node67--> |"true"| node49
	node67--> |"id"| node50
	node67--> |"factor"| node48
	node67--> |"false"| node47
	node67--> |"num"| node45
	node67--> |"("| node44
	node67--> |"!"| node43
	node67--> |"-"| node46
	node67--> |"unary"| node83
	node68("<div>I68:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·! unary <br>unary → ·- unary <br>term → term * ·unary <br></div>")
	node68--> |"true"| node49
	node68--> |"id"| node50
	node68--> |"factor"| node48
	node68--> |"false"| node47
	node68--> |"num"| node45
	node68--> |"("| node44
	node68--> |"!"| node43
	node68--> |"-"| node46
	node68--> |"unary"| node84
	node69("<div>I69:<br>array_assignment → id [ num ] ·= expr ; <br></div>")
	node69--> |"="| node85
	node70("<div>I70:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>rel → expr <= ·expr <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br></div>")
	node70--> |"term"| node51
	node70--> |"true"| node49
	node70--> |"id"| node50
	node70--> |"factor"| node48
	node70--> |"false"| node47
	node70--> |"num"| node45
	node70--> |"("| node44
	node70--> |"!"| node43
	node70--> |"-"| node46
	node70--> |"unary"| node42
	node70--> |"expr"| node86
	node71("<div>I71:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>rel → expr > ·expr <br>expr → ·expr - term <br>expr → ·expr + term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br></div>")
	node71--> |"term"| node51
	node71--> |"true"| node49
	node71--> |"id"| node50
	node71--> |"factor"| node48
	node71--> |"false"| node47
	node71--> |"num"| node45
	node71--> |"("| node44
	node71--> |"!"| node43
	node71--> |"-"| node46
	node71--> |"unary"| node42
	node71--> |"expr"| node87
	node72("<div>I72:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>rel → expr < ·expr <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br></div>")
	node72--> |"term"| node51
	node72--> |"true"| node49
	node72--> |"id"| node50
	node72--> |"factor"| node48
	node72--> |"false"| node47
	node72--> |"num"| node45
	node72--> |"("| node44
	node72--> |"!"| node43
	node72--> |"-"| node46
	node72--> |"unary"| node42
	node72--> |"expr"| node88
	node73("<div>I73:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>rel → expr >= ·expr <br>unary → ·- unary <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br></div>")
	node73--> |"term"| node51
	node73--> |"true"| node49
	node73--> |"id"| node50
	node73--> |"factor"| node48
	node73--> |"false"| node47
	node73--> |"num"| node45
	node73--> |"("| node44
	node73--> |"!"| node43
	node73--> |"-"| node46
	node73--> |"unary"| node42
	node73--> |"expr"| node89
	node74("<div>I74:<br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ num ] = expr ; <br>while_loop → while ( bool ) ·stmt_or_block <br>stmt → ·if_stmt <br>stmt_or_block → ·stmt <br>stmt_or_block → ·block <br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>block → ·{ declarations stmts } <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>declaration → ·basics id ; <br>declaration → ·array_declaration ; <br></div>")
	node74--> |"block"| node92
	node74--> |"{"| node10
	node74--> |"while"| node27
	node74--> |"if"| node28
	node74--> |"assignment"| node18
	node74--> |"int"| node5
	node74--> |"float"| node6
	node74--> |"if_stmt"| node19
	node74--> |"basics"| node12
	node74--> |"stmt_or_block"| node90
	node74--> |"while_loop"| node20
	node74--> |"id"| node26
	node74--> |"array_assignment"| node29
	node74--> |"void"| node4
	node74--> |"break_stmt"| node21
	node74--> |"declaration"| node23
	node74--> |"stmt"| node91
	node74--> |"array_declaration"| node15
	node74--> |"break"| node24
	node75("<div>I75:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>equality → equality == ·rel <br>expr → ·expr - term <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·expr + term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br></div>")
	node75--> |"id"| node50
	node75--> |"factor"| node48
	node75--> |"false"| node47
	node75--> |"num"| node45
	node75--> |"("| node44
	node75--> |"!"| node43
	node75--> |"-"| node46
	node75--> |"unary"| node42
	node75--> |"term"| node51
	node75--> |"true"| node49
	node75--> |"rel"| node93
	node75--> |"expr"| node53
	node76("<div>I76:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>equality → equality != ·rel <br>expr → ·term <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·expr + term <br>expr → ·expr - term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br></div>")
	node76--> |"id"| node50
	node76--> |"factor"| node48
	node76--> |"false"| node47
	node76--> |"num"| node45
	node76--> |"("| node44
	node76--> |"!"| node43
	node76--> |"-"| node46
	node76--> |"unary"| node42
	node76--> |"term"| node51
	node76--> |"true"| node49
	node76--> |"rel"| node94
	node76--> |"expr"| node53
	node77("<div>I77:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>join → join && ·equality <br>rel → ·expr <br>equality → ·equality == rel <br>equality → ·equality != rel <br>equality → ·rel <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br></div>")
	node77--> |"id"| node50
	node77--> |"factor"| node48
	node77--> |"false"| node47
	node77--> |"num"| node45
	node77--> |"("| node44
	node77--> |"!"| node43
	node77--> |"-"| node46
	node77--> |"unary"| node42
	node77--> |"equality"| node95
	node77--> |"term"| node51
	node77--> |"true"| node49
	node77--> |"rel"| node55
	node77--> |"expr"| node53
	node78("<div>I78:<br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ num ] = expr ; <br>if_stmt → if ( bool ) ·stmt_or_block block_tail <br>stmt → ·if_stmt <br>stmt_or_block → ·stmt <br>stmt_or_block → ·block <br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>block → ·{ declarations stmts } <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>declaration → ·basics id ; <br>declaration → ·array_declaration ; <br></div>")
	node78--> |"block"| node92
	node78--> |"{"| node10
	node78--> |"while"| node27
	node78--> |"if"| node28
	node78--> |"assignment"| node18
	node78--> |"int"| node5
	node78--> |"float"| node6
	node78--> |"if_stmt"| node19
	node78--> |"basics"| node12
	node78--> |"stmt_or_block"| node96
	node78--> |"while_loop"| node20
	node78--> |"id"| node26
	node78--> |"array_assignment"| node29
	node78--> |"void"| node4
	node78--> |"break_stmt"| node21
	node78--> |"declaration"| node23
	node78--> |"stmt"| node91
	node78--> |"array_declaration"| node15
	node78--> |"break"| node24
	node79("<div>I79:<br>expr → expr - term ·<br>term → term ·* unary <br>term → term ·/ unary <br></div>")
	node79--> |"*"| node68
	node79--> |"/"| node67
	node80("<div>I80:<br>expr → expr + term ·<br>term → term ·* unary <br>term → term ·/ unary <br></div>")
	node80--> |"*"| node68
	node80--> |"/"| node67
	node81("<div>I81:<br>factor → ( expr ) ·<br></div>")
	node82("<div>I82:<br>factor → id [ num ·] <br></div>")
	node82--> |"]"| node97
	node83("<div>I83:<br>term → term / unary ·<br></div>")
	node84("<div>I84:<br>term → term * unary ·<br></div>")
	node85("<div>I85:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>array_assignment → id [ num ] = ·expr ; <br>term → ·unary <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br></div>")
	node85--> |"term"| node51
	node85--> |"true"| node49
	node85--> |"id"| node50
	node85--> |"factor"| node48
	node85--> |"false"| node47
	node85--> |"num"| node45
	node85--> |"("| node44
	node85--> |"!"| node43
	node85--> |"-"| node46
	node85--> |"unary"| node42
	node85--> |"expr"| node98
	node86("<div>I86:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr <= expr ·<br></div>")
	node86--> |"+"| node62
	node86--> |"-"| node60
	node87("<div>I87:<br>expr → expr ·+ term <br>expr → expr ·- term <br>rel → expr > expr ·<br></div>")
	node87--> |"+"| node62
	node87--> |"-"| node60
	node88("<div>I88:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr < expr ·<br></div>")
	node88--> |"+"| node62
	node88--> |"-"| node60
	node89("<div>I89:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr >= expr ·<br></div>")
	node89--> |"+"| node62
	node89--> |"-"| node60
	node90("<div>I90:<br>while_loop → while ( bool ) stmt_or_block ·<br></div>")
	node91("<div>I91:<br>stmt_or_block → stmt ·<br></div>")
	node92("<div>I92:<br>stmt_or_block → block ·<br></div>")
	node93("<div>I93:<br>equality → equality == rel ·<br></div>")
	node94("<div>I94:<br>equality → equality != rel ·<br></div>")
	node95("<div>I95:<br>equality → equality ·!= rel <br>equality → equality ·== rel <br>join → join && equality ·<br></div>")
	node95--> |"!="| node76
	node95--> |"=="| node75
	node96("<div>I96:<br>block_tail → ·else stmt_or_block <br>block_tail → ε ·<br>if_stmt → if ( bool ) stmt_or_block ·block_tail <br></div>")
	node96--> |"else"| node100
	node96--> |"block_tail"| node99
	node97("<div>I97:<br>factor → id [ num ] ·<br></div>")
	node98("<div>I98:<br>expr → expr ·+ term <br>expr → expr ·- term <br>array_assignment → id [ num ] = expr ·; <br></div>")
	node98--> |"+"| node62
	node98--> |";"| node101
	node98--> |"-"| node60
	node99("<div>I99:<br>if_stmt → if ( bool ) stmt_or_block block_tail ·<br></div>")
	node100("<div>I100:<br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>basics → ·void <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ num ] = expr ; <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>block_tail → else ·stmt_or_block <br>stmt_or_block → ·stmt <br>stmt_or_block → ·block <br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>block → ·{ declarations stmts } <br>stmt → ·if_stmt <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>declaration → ·basics id ; <br>declaration → ·array_declaration ; <br></div>")
	node100--> |"block"| node92
	node100--> |"{"| node10
	node100--> |"while"| node27
	node100--> |"if"| node28
	node100--> |"assignment"| node18
	node100--> |"int"| node5
	node100--> |"float"| node6
	node100--> |"if_stmt"| node19
	node100--> |"basics"| node12
	node100--> |"stmt_or_block"| node102
	node100--> |"while_loop"| node20
	node100--> |"id"| node26
	node100--> |"array_assignment"| node29
	node100--> |"void"| node4
	node100--> |"break_stmt"| node21
	node100--> |"declaration"| node23
	node100--> |"stmt"| node91
	node100--> |"array_declaration"| node15
	node100--> |"break"| node24
	node101("<div>I101:<br>array_assignment → id [ num ] = expr ; ·<br></div>")
	node102("<div>I102:<br>block_tail → else stmt_or_block ·<br></div>")
```
