```mermaid
graph LR
node0("<div>I0:<br>basics → ·float <br>basics → ·int <br>program → ·basics id ( ) block <br>S → ·program <br>START → ·S <br>"</div>)
node0--> |"float"| node5
node0--> |"int"| node4
node0--> |"program"| node3
node0--> |"S"| node2
node0--> |"basics"| node1
node1("<div>I1:<br>program → basics ·id ( ) block <br>"</div>)
node1--> |"id"| node6
node2("<div>I2:<br>START → S ·<br>"</div>)
node3("<div>I3:<br>S → program ·<br>"</div>)
node4("<div>I4:<br>basics → int ·<br>"</div>)
node5("<div>I5:<br>basics → float ·<br>"</div>)
node6("<div>I6:<br>program → basics id ·( ) block <br>"</div>)
node6--> |"("| node7
node7("<div>I7:<br>program → basics id ( ·) block <br>"</div>)
node7--> |")"| node8
node8("<div>I8:<br>block → ·{ declarations stmts } <br>program → basics id ( ) ·block <br>"</div>)
node8--> |"block"| node10
node8--> |"{"| node9
node9("<div>I9:<br>basics → ·float <br>basics → ·int <br>array_declaration → ·basics id [ num ] <br>declaration → ·basics id ; <br>declaration → ·array_declaration ; <br>declarations → ε ·<br>declarations → ·declaration declarations <br>block → { ·declarations stmts } <br>"</div>)
node9--> |"int"| node4
node9--> |"float"| node5
node9--> |"array_declaration"| node14
node9--> |"declarations"| node13
node9--> |"declaration"| node12
node9--> |"basics"| node11
node10("<div>I10:<br>program → basics id ( ) block ·<br>"</div>)
node11("<div>I11:<br>declaration → basics ·id ; <br>array_declaration → basics ·id [ num ] <br>"</div>)
node11--> |"id"| node15
node12("<div>I12:<br>basics → ·float <br>basics → ·int <br>array_declaration → ·basics id [ num ] <br>declaration → ·basics id ; <br>declaration → ·array_declaration ; <br>declarations → ε ·<br>declarations → ·declaration declarations <br>declarations → declaration ·declarations <br>"</div>)
node12--> |"int"| node4
node12--> |"float"| node5
node12--> |"array_declaration"| node14
node12--> |"declarations"| node16
node12--> |"declaration"| node12
node12--> |"basics"| node11
node13("<div>I13:<br>array_declaration → ·basics id [ num ] <br>basics → ·int <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool ) stmt_or_block <br>block → { declarations ·stmts } <br>declaration → ·array_declaration ; <br>array_assignment → ·id [ num ] = expr ; <br>stmts → ·stmt stmts <br>basics → ·float <br>stmts → ε ·<br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>stmt → ·if_stmt <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>declaration → ·basics id ; <br>"</div>)
node13--> |"if"| node27
node13--> |"assignment"| node17
node13--> |"int"| node4
node13--> |"float"| node5
node13--> |"if_stmt"| node18
node13--> |"basics"| node11
node13--> |"stmts"| node23
node13--> |"while_loop"| node19
node13--> |"id"| node24
node13--> |"array_assignment"| node28
node13--> |"break_stmt"| node20
node13--> |"declaration"| node22
node13--> |"stmt"| node21
node13--> |"array_declaration"| node14
node13--> |"break"| node25
node13--> |"while"| node26
node14("<div>I14:<br>declaration → array_declaration ·; <br>"</div>)
node14--> |";"| node29
node15("<div>I15:<br>array_declaration → basics id ·[ num ] <br>declaration → basics id ·; <br>"</div>)
node15--> |";"| node31
node15--> |"["| node30
node16("<div>I16:<br>declarations → declaration declarations ·<br>"</div>)
node17("<div>I17:<br>stmt → assignment ·<br>"</div>)
node18("<div>I18:<br>stmt → if_stmt ·<br>"</div>)
node19("<div>I19:<br>stmt → while_loop ·<br>"</div>)
node20("<div>I20:<br>stmt → break_stmt ·<br>"</div>)
node21("<div>I21:<br>array_declaration → ·basics id [ num ] <br>basics → ·int <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool ) stmt_or_block <br>stmts → stmt ·stmts <br>stmt → ·assignment <br>stmts → ·stmt stmts <br>basics → ·float <br>stmts → ε ·<br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>stmt → ·if_stmt <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>declaration → ·basics id ; <br>declaration → ·array_declaration ; <br>array_assignment → ·id [ num ] = expr ; <br>"</div>)
node21--> |"if"| node27
node21--> |"assignment"| node17
node21--> |"int"| node4
node21--> |"float"| node5
node21--> |"if_stmt"| node18
node21--> |"basics"| node11
node21--> |"stmts"| node32
node21--> |"while_loop"| node19
node21--> |"id"| node24
node21--> |"array_assignment"| node28
node21--> |"break_stmt"| node20
node21--> |"declaration"| node22
node21--> |"stmt"| node21
node21--> |"array_declaration"| node14
node21--> |"break"| node25
node21--> |"while"| node26
node22("<div>I22:<br>stmt → declaration ·<br>"</div>)
node23("<div>I23:<br>block → { declarations stmts ·} <br>"</div>)
node23--> |"}"| node33
node24("<div>I24:<br>assignment → id ·= expr ; <br>array_assignment → id ·[ num ] = expr ; <br>"</div>)
node24--> |"["| node35
node24--> |"="| node34
node25("<div>I25:<br>break_stmt → break ·; <br>"</div>)
node25--> |";"| node36
node26("<div>I26:<br>while_loop → while ·( bool ) stmt_or_block <br>"</div>)
node26--> |"("| node37
node27("<div>I27:<br>if_stmt → if ·( bool ) stmt_or_block block_tail <br>"</div>)
node27--> |"("| node38
node28("<div>I28:<br>stmt → array_assignment ·<br>"</div>)
node29("<div>I29:<br>declaration → array_declaration ; ·<br>"</div>)
node30("<div>I30:<br>array_declaration → basics id [ ·num ] <br>"</div>)
node30--> |"num"| node39
node31("<div>I31:<br>declaration → basics id ; ·<br>"</div>)
node32("<div>I32:<br>stmts → stmt stmts ·<br>"</div>)
node33("<div>I33:<br>block → { declarations stmts } ·<br>"</div>)
node34("<div>I34:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>assignment → id = ·expr ; <br>factor → ·( expr ) <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·id <br>factor → ·id [ num ] <br>"</div>)
node34--> |"factor"| node50
node34--> |"id"| node48
node34--> |"false"| node47
node34--> |"true"| node49
node34--> |"term"| node46
node34--> |"num"| node44
node34--> |"("| node43
node34--> |"!"| node42
node34--> |"-"| node45
node34--> |"unary"| node41
node34--> |"expr"| node40
node35("<div>I35:<br>array_assignment → id [ ·num ] = expr ; <br>"</div>)
node35--> |"num"| node51
node36("<div>I36:<br>break_stmt → break ; ·<br>"</div>)
node37("<div>I37:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>term → ·term * unary <br>expr → ·term <br>expr → ·expr - term <br>expr → ·expr + term <br>unary → ·- unary <br>while_loop → while ( ·bool ) stmt_or_block <br>join → ·equality <br>bool → ·bool || join <br>bool → ·join <br>join → ·join && equality <br>equality → ·equality == rel <br>equality → ·equality != rel <br>equality → ·rel <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>"</div>)
node37--> |"true"| node49
node37--> |"expr"| node52
node37--> |"bool"| node53
node37--> |"rel"| node54
node37--> |"term"| node46
node37--> |"equality"| node55
node37--> |"unary"| node41
node37--> |"-"| node45
node37--> |"("| node43
node37--> |"num"| node44
node37--> |"join"| node56
node37--> |"!"| node42
node37--> |"false"| node47
node37--> |"factor"| node50
node37--> |"id"| node48
node38("<div>I38:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>term → ·term * unary <br>expr → ·term <br>expr → ·expr - term <br>expr → ·expr + term <br>factor → ·id <br>if_stmt → if ( ·bool ) stmt_or_block block_tail <br>equality → ·rel <br>bool → ·bool || join <br>bool → ·join <br>join → ·join && equality <br>join → ·equality <br>equality → ·equality == rel <br>equality → ·equality != rel <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>"</div>)
node38--> |"true"| node49
node38--> |"expr"| node52
node38--> |"bool"| node57
node38--> |"rel"| node54
node38--> |"term"| node46
node38--> |"equality"| node55
node38--> |"unary"| node41
node38--> |"-"| node45
node38--> |"("| node43
node38--> |"num"| node44
node38--> |"join"| node56
node38--> |"!"| node42
node38--> |"false"| node47
node38--> |"factor"| node50
node38--> |"id"| node48
node39("<div>I39:<br>array_declaration → basics id [ num ·] <br>"</div>)
node39--> |"]"| node58
node40("<div>I40:<br>expr → expr ·- term <br>expr → expr ·+ term <br>assignment → id = expr ·; <br>"</div>)
node40--> |"+"| node61
node40--> |";"| node60
node40--> |"-"| node59
node41("<div>I41:<br>term → unary ·<br>"</div>)
node42("<div>I42:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·- unary <br>unary → ·! unary <br>unary → ·factor <br>unary → ! ·unary <br>"</div>)
node42--> |"true"| node49
node42--> |"factor"| node50
node42--> |"id"| node48
node42--> |"false"| node47
node42--> |"num"| node44
node42--> |"("| node43
node42--> |"!"| node42
node42--> |"-"| node45
node42--> |"unary"| node62
node43("<div>I43:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ( ·expr ) <br>unary → ·- unary <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br>"</div>)
node43--> |"factor"| node50
node43--> |"id"| node48
node43--> |"false"| node47
node43--> |"true"| node49
node43--> |"term"| node46
node43--> |"num"| node44
node43--> |"("| node43
node43--> |"!"| node42
node43--> |"-"| node45
node43--> |"unary"| node41
node43--> |"expr"| node63
node44("<div>I44:<br>factor → num ·<br>"</div>)
node45("<div>I45:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>factor → ·( expr ) <br>unary → - ·unary <br>"</div>)
node45--> |"true"| node49
node45--> |"factor"| node50
node45--> |"id"| node48
node45--> |"false"| node47
node45--> |"num"| node44
node45--> |"("| node43
node45--> |"!"| node42
node45--> |"-"| node45
node45--> |"unary"| node64
node46("<div>I46:<br>term → term ·/ unary <br>term → term ·* unary <br>expr → term ·<br>"</div>)
node46--> |"*"| node66
node46--> |"/"| node65
node47("<div>I47:<br>factor → false ·<br>"</div>)
node48("<div>I48:<br>factor → id ·[ num ] <br>factor → id ·<br>"</div>)
node48--> |"["| node67
node49("<div>I49:<br>factor → true ·<br>"</div>)
node50("<div>I50:<br>unary → factor ·<br>"</div>)
node51("<div>I51:<br>array_assignment → id [ num ·] = expr ; <br>"</div>)
node51--> |"]"| node68
node52("<div>I52:<br>rel → expr ·<br>rel → expr ·>= expr <br>rel → expr ·> expr <br>rel → expr ·<= expr <br>rel → expr ·< expr <br>expr → expr ·+ term <br>expr → expr ·- term <br>"</div>)
node52--> |">="| node72
node52--> |"+"| node61
node52--> |"<"| node71
node52--> |">"| node70
node52--> |"<="| node69
node52--> |"-"| node59
node53("<div>I53:<br>bool → bool ·|| join <br>while_loop → while ( bool ·) stmt_or_block <br>"</div>)
node53--> |"||"| node74
node53--> |")"| node73
node54("<div>I54:<br>equality → rel ·<br>"</div>)
node55("<div>I55:<br>equality → equality ·!= rel <br>equality → equality ·== rel <br>join → equality ·<br>"</div>)
node55--> |"!="| node76
node55--> |"=="| node75
node56("<div>I56:<br>join → join ·&& equality <br>bool → join ·<br>"</div>)
node56--> |"&&"| node77
node57("<div>I57:<br>bool → bool ·|| join <br>if_stmt → if ( bool ·) stmt_or_block block_tail <br>"</div>)
node57--> |"||"| node74
node57--> |")"| node78
node58("<div>I58:<br>array_declaration → basics id [ num ] ·<br>"</div>)
node59("<div>I59:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>term → ·term * unary <br>factor → ·id <br>expr → expr - ·term <br>"</div>)
node59--> |"factor"| node50
node59--> |"id"| node48
node59--> |"false"| node47
node59--> |"true"| node49
node59--> |"term"| node79
node59--> |"num"| node44
node59--> |"("| node43
node59--> |"!"| node42
node59--> |"-"| node45
node59--> |"unary"| node41
node60("<div>I60:<br>assignment → id = expr ; ·<br>"</div>)
node61("<div>I61:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>term → ·term * unary <br>factor → ·( expr ) <br>expr → expr + ·term <br>"</div>)
node61--> |"factor"| node50
node61--> |"id"| node48
node61--> |"false"| node47
node61--> |"true"| node49
node61--> |"term"| node80
node61--> |"num"| node44
node61--> |"("| node43
node61--> |"!"| node42
node61--> |"-"| node45
node61--> |"unary"| node41
node62("<div>I62:<br>unary → ! unary ·<br>"</div>)
node63("<div>I63:<br>expr → expr ·- term <br>expr → expr ·+ term <br>factor → ( expr ·) <br>"</div>)
node63--> |"+"| node61
node63--> |"-"| node59
node63--> |")"| node81
node64("<div>I64:<br>unary → - unary ·<br>"</div>)
node65("<div>I65:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·- unary <br>unary → ·! unary <br>unary → ·factor <br>term → term / ·unary <br>"</div>)
node65--> |"true"| node49
node65--> |"factor"| node50
node65--> |"id"| node48
node65--> |"false"| node47
node65--> |"num"| node44
node65--> |"("| node43
node65--> |"!"| node42
node65--> |"-"| node45
node65--> |"unary"| node82
node66("<div>I66:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·! unary <br>unary → ·- unary <br>term → term * ·unary <br>"</div>)
node66--> |"true"| node49
node66--> |"factor"| node50
node66--> |"id"| node48
node66--> |"false"| node47
node66--> |"num"| node44
node66--> |"("| node43
node66--> |"!"| node42
node66--> |"-"| node45
node66--> |"unary"| node83
node67("<div>I67:<br>factor → id [ ·num ] <br>"</div>)
node67--> |"num"| node84
node68("<div>I68:<br>array_assignment → id [ num ] ·= expr ; <br>"</div>)
node68--> |"="| node85
node69("<div>I69:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>rel → expr <= ·expr <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br>"</div>)
node69--> |"factor"| node50
node69--> |"id"| node48
node69--> |"false"| node47
node69--> |"true"| node49
node69--> |"term"| node46
node69--> |"num"| node44
node69--> |"("| node43
node69--> |"!"| node42
node69--> |"-"| node45
node69--> |"unary"| node41
node69--> |"expr"| node86
node70("<div>I70:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>rel → expr > ·expr <br>expr → ·expr - term <br>expr → ·expr + term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br>"</div>)
node70--> |"factor"| node50
node70--> |"id"| node48
node70--> |"false"| node47
node70--> |"true"| node49
node70--> |"term"| node46
node70--> |"num"| node44
node70--> |"("| node43
node70--> |"!"| node42
node70--> |"-"| node45
node70--> |"unary"| node41
node70--> |"expr"| node87
node71("<div>I71:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>rel → expr < ·expr <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br>"</div>)
node71--> |"factor"| node50
node71--> |"id"| node48
node71--> |"false"| node47
node71--> |"true"| node49
node71--> |"term"| node46
node71--> |"num"| node44
node71--> |"("| node43
node71--> |"!"| node42
node71--> |"-"| node45
node71--> |"unary"| node41
node71--> |"expr"| node88
node72("<div>I72:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>rel → expr >= ·expr <br>unary → ·- unary <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br>"</div>)
node72--> |"factor"| node50
node72--> |"id"| node48
node72--> |"false"| node47
node72--> |"true"| node49
node72--> |"term"| node46
node72--> |"num"| node44
node72--> |"("| node43
node72--> |"!"| node42
node72--> |"-"| node45
node72--> |"unary"| node41
node72--> |"expr"| node89
node73("<div>I73:<br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ num ] = expr ; <br>while_loop → while ( bool ) ·stmt_or_block <br>stmt → ·if_stmt <br>block → ·{ declarations stmts } <br>stmt_or_block → ·stmt <br>stmt_or_block → ·block <br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>declaration → ·basics id ; <br>declaration → ·array_declaration ; <br>"</div>)
node73--> |"block"| node92
node73--> |"{"| node9
node73--> |"if"| node27
node73--> |"assignment"| node17
node73--> |"int"| node4
node73--> |"float"| node5
node73--> |"if_stmt"| node18
node73--> |"basics"| node11
node73--> |"stmt_or_block"| node90
node73--> |"while_loop"| node19
node73--> |"id"| node24
node73--> |"array_assignment"| node28
node73--> |"break_stmt"| node20
node73--> |"declaration"| node22
node73--> |"stmt"| node91
node73--> |"array_declaration"| node14
node73--> |"break"| node25
node73--> |"while"| node26
node74("<div>I74:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>term → ·term * unary <br>expr → ·term <br>bool → bool || ·join <br>equality → ·equality == rel <br>join → ·join && equality <br>join → ·equality <br>equality → ·equality != rel <br>equality → ·rel <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·expr + term <br>expr → ·expr - term <br>"</div>)
node74--> |"expr"| node52
node74--> |"rel"| node54
node74--> |"term"| node46
node74--> |"true"| node49
node74--> |"equality"| node55
node74--> |"unary"| node41
node74--> |"-"| node45
node74--> |"("| node43
node74--> |"num"| node44
node74--> |"join"| node93
node74--> |"!"| node42
node74--> |"false"| node47
node74--> |"factor"| node50
node74--> |"id"| node48
node75("<div>I75:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>equality → equality == ·rel <br>expr → ·expr - term <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·expr + term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>"</div>)
node75--> |"factor"| node50
node75--> |"id"| node48
node75--> |"false"| node47
node75--> |"num"| node44
node75--> |"("| node43
node75--> |"!"| node42
node75--> |"-"| node45
node75--> |"unary"| node41
node75--> |"true"| node49
node75--> |"term"| node46
node75--> |"rel"| node94
node75--> |"expr"| node52
node76("<div>I76:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>equality → equality != ·rel <br>expr → ·term <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>rel → ·expr <br>expr → ·expr + term <br>expr → ·expr - term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>"</div>)
node76--> |"factor"| node50
node76--> |"id"| node48
node76--> |"false"| node47
node76--> |"num"| node44
node76--> |"("| node43
node76--> |"!"| node42
node76--> |"-"| node45
node76--> |"unary"| node41
node76--> |"true"| node49
node76--> |"term"| node46
node76--> |"rel"| node95
node76--> |"expr"| node52
node77("<div>I77:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>factor → ·id [ num ] <br>factor → ·id <br>factor → ·( expr ) <br>unary → ·factor <br>unary → ·- unary <br>unary → ·! unary <br>term → ·unary <br>term → ·term / unary <br>join → join && ·equality <br>rel → ·expr <br>equality → ·equality == rel <br>equality → ·equality != rel <br>equality → ·rel <br>rel → ·expr < expr <br>rel → ·expr <= expr <br>rel → ·expr > expr <br>rel → ·expr >= expr <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>"</div>)
node77--> |"factor"| node50
node77--> |"id"| node48
node77--> |"false"| node47
node77--> |"num"| node44
node77--> |"("| node43
node77--> |"!"| node42
node77--> |"-"| node45
node77--> |"unary"| node41
node77--> |"equality"| node96
node77--> |"true"| node49
node77--> |"term"| node46
node77--> |"rel"| node54
node77--> |"expr"| node52
node78("<div>I78:<br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ num ] = expr ; <br>declaration → ·basics id ; <br>stmt_or_block → ·stmt <br>stmt_or_block → ·block <br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt → ·while_loop <br>stmt → ·if_stmt <br>if_stmt → if ( bool ) ·stmt_or_block block_tail <br>block → ·{ declarations stmts } <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>declaration → ·array_declaration ; <br>"</div>)
node78--> |"block"| node92
node78--> |"{"| node9
node78--> |"if"| node27
node78--> |"assignment"| node17
node78--> |"int"| node4
node78--> |"float"| node5
node78--> |"if_stmt"| node18
node78--> |"basics"| node11
node78--> |"stmt_or_block"| node97
node78--> |"while_loop"| node19
node78--> |"id"| node24
node78--> |"array_assignment"| node28
node78--> |"break_stmt"| node20
node78--> |"declaration"| node22
node78--> |"stmt"| node91
node78--> |"array_declaration"| node14
node78--> |"break"| node25
node78--> |"while"| node26
node79("<div>I79:<br>expr → expr - term ·<br>term → term ·* unary <br>term → term ·/ unary <br>"</div>)
node79--> |"*"| node66
node79--> |"/"| node65
node80("<div>I80:<br>expr → expr + term ·<br>term → term ·* unary <br>term → term ·/ unary <br>"</div>)
node80--> |"*"| node66
node80--> |"/"| node65
node81("<div>I81:<br>factor → ( expr ) ·<br>"</div>)
node82("<div>I82:<br>term → term / unary ·<br>"</div>)
node83("<div>I83:<br>term → term * unary ·<br>"</div>)
node84("<div>I84:<br>factor → id [ num ·] <br>"</div>)
node84--> |"]"| node98
node85("<div>I85:<br>factor → ·false <br>factor → ·true <br>factor → ·num <br>array_assignment → id [ num ] = ·expr ; <br>expr → ·expr + term <br>expr → ·expr - term <br>expr → ·term <br>term → ·term * unary <br>term → ·term / unary <br>term → ·unary <br>unary → ·! unary <br>unary → ·- unary <br>unary → ·factor <br>factor → ·( expr ) <br>factor → ·id <br>factor → ·id [ num ] <br>"</div>)
node85--> |"factor"| node50
node85--> |"id"| node48
node85--> |"false"| node47
node85--> |"true"| node49
node85--> |"term"| node46
node85--> |"num"| node44
node85--> |"("| node43
node85--> |"!"| node42
node85--> |"-"| node45
node85--> |"unary"| node41
node85--> |"expr"| node99
node86("<div>I86:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr <= expr ·<br>"</div>)
node86--> |"+"| node61
node86--> |"-"| node59
node87("<div>I87:<br>expr → expr ·+ term <br>expr → expr ·- term <br>rel → expr > expr ·<br>"</div>)
node87--> |"+"| node61
node87--> |"-"| node59
node88("<div>I88:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr < expr ·<br>"</div>)
node88--> |"+"| node61
node88--> |"-"| node59
node89("<div>I89:<br>expr → expr ·- term <br>expr → expr ·+ term <br>rel → expr >= expr ·<br>"</div>)
node89--> |"+"| node61
node89--> |"-"| node59
node90("<div>I90:<br>while_loop → while ( bool ) stmt_or_block ·<br>"</div>)
node91("<div>I91:<br>stmt_or_block → stmt ·<br>"</div>)
node92("<div>I92:<br>stmt_or_block → block ·<br>"</div>)
node93("<div>I93:<br>join → join ·&& equality <br>bool → bool || join ·<br>"</div>)
node93--> |"&&"| node77
node94("<div>I94:<br>equality → equality == rel ·<br>"</div>)
node95("<div>I95:<br>equality → equality != rel ·<br>"</div>)
node96("<div>I96:<br>equality → equality ·!= rel <br>equality → equality ·== rel <br>join → join && equality ·<br>"</div>)
node96--> |"!="| node76
node96--> |"=="| node75
node97("<div>I97:<br>block_tail → ·else stmt_or_block <br>block_tail → ε ·<br>if_stmt → if ( bool ) stmt_or_block ·block_tail <br>"</div>)
node97--> |"else"| node101
node97--> |"block_tail"| node100
node98("<div>I98:<br>factor → id [ num ] ·<br>"</div>)
node99("<div>I99:<br>expr → expr ·- term <br>expr → expr ·+ term <br>array_assignment → id [ num ] = expr ·; <br>"</div>)
node99--> |"+"| node61
node99--> |";"| node102
node99--> |"-"| node59
node100("<div>I100:<br>if_stmt → if ( bool ) stmt_or_block block_tail ·<br>"</div>)
node101("<div>I101:<br>array_declaration → ·basics id [ num ] <br>basics → ·float <br>basics → ·int <br>break_stmt → ·break ; <br>if_stmt → ·if ( bool ) stmt_or_block block_tail <br>while_loop → ·while ( bool ) stmt_or_block <br>array_assignment → ·id [ num ] = expr ; <br>block_tail → else ·stmt_or_block <br>stmt → ·while_loop <br>stmt_or_block → ·stmt <br>stmt_or_block → ·block <br>stmt → ·assignment <br>stmt → ·declaration <br>stmt → ·array_assignment <br>stmt → ·if_stmt <br>block → ·{ declarations stmts } <br>stmt → ·break_stmt <br>assignment → ·id = expr ; <br>declaration → ·basics id ; <br>declaration → ·array_declaration ; <br>"</div>)
node101--> |"block"| node92
node101--> |"{"| node9
node101--> |"if"| node27
node101--> |"assignment"| node17
node101--> |"int"| node4
node101--> |"float"| node5
node101--> |"if_stmt"| node18
node101--> |"basics"| node11
node101--> |"stmt_or_block"| node103
node101--> |"while_loop"| node19
node101--> |"id"| node24
node101--> |"array_assignment"| node28
node101--> |"break_stmt"| node20
node101--> |"declaration"| node22
node101--> |"stmt"| node91
node101--> |"array_declaration"| node14
node101--> |"break"| node25
node101--> |"while"| node26
node102("<div>I102:<br>array_assignment → id [ num ] = expr ; ·<br>"</div>)
node103("<div>I103:<br>block_tail → else stmt_or_block ·<br>"</div>)
