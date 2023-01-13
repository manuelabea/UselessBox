SamacSys ECAD Model
978758/1051981/2.49/3/3/MOSFET N-Channel

DESIGNSPARK_INTERMEDIATE_ASCII

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "r100_70"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 0.7) (shapeHeight 1))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(textStyleDef "Default"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 50 mils)
			(strokeWidth 5 mils)
		)
	)
	(patternDef "SOT95P240X120-3N" (originalName "SOT95P240X120-3N")
		(multiLayer
			(pad (padNum 1) (padStyleRef r100_70) (pt -1.2, 0.95) (rotation 90))
			(pad (padNum 2) (padStyleRef r100_70) (pt -1.2, -0.95) (rotation 90))
			(pad (padNum 3) (padStyleRef r100_70) (pt 1.2, 0) (rotation 90))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 0, 0) (textStyleRef "Default") (isVisible True))
		)
		(layerContents (layerNumRef 30)
			(line (pt -1.95 1.81) (pt 1.95 1.81) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt 1.95 1.81) (pt 1.95 -1.81) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt 1.95 -1.81) (pt -1.95 -1.81) (width 0.05))
		)
		(layerContents (layerNumRef 30)
			(line (pt -1.95 -1.81) (pt -1.95 1.81) (width 0.05))
		)
		(layerContents (layerNumRef 28)
			(line (pt -0.662 1.46) (pt 0.662 1.46) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt 0.662 1.46) (pt 0.662 -1.46) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt 0.662 -1.46) (pt -0.662 -1.46) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt -0.662 -1.46) (pt -0.662 1.46) (width 0.1))
		)
		(layerContents (layerNumRef 28)
			(line (pt -0.662 0.51) (pt 0.288 1.46) (width 0.1))
		)
		(layerContents (layerNumRef 18)
			(line (pt -0.35 1.46) (pt 0.35 1.46) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 0.35 1.46) (pt 0.35 -1.46) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 0.35 -1.46) (pt -0.35 -1.46) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -0.35 -1.46) (pt -0.35 1.46) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -1.7 1.55) (pt -0.7 1.55) (width 0.2))
		)
	)
	(symbolDef "BSS138" (originalName "BSS138")

		(pin (pinNum 1) (pt 0 mils 0 mils) (rotation 0) (pinLength 100 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 0 mils -45 mils) (rotation 0]) (justify "UpperLeft") (textStyleRef "Default"))
		))
		(pin (pinNum 2) (pt 300 mils 400 mils) (rotation 270) (pinLength 100 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 305 mils 400 mils) (rotation 90]) (justify "UpperLeft") (textStyleRef "Default"))
		))
		(pin (pinNum 3) (pt 300 mils -200 mils) (rotation 90) (pinLength 100 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 305 mils -200 mils) (rotation 90]) (justify "LowerLeft") (textStyleRef "Default"))
		))
		(line (pt 300 mils 100 mils) (pt 300 mils -100 mils) (width 6 mils))
		(line (pt 300 mils 200 mils) (pt 300 mils 300 mils) (width 6 mils))
		(line (pt 100 mils 0 mils) (pt 200 mils 0 mils) (width 6 mils))
		(line (pt 200 mils 0 mils) (pt 200 mils 200 mils) (width 6 mils))
		(line (pt 300 mils 100 mils) (pt 230 mils 100 mils) (width 6 mils))
		(line (pt 300 mils 200 mils) (pt 230 mils 200 mils) (width 6 mils))
		(line (pt 230 mils 0 mils) (pt 300 mils 0 mils) (width 6 mils))
		(line (pt 230 mils 220 mils) (pt 230 mils 180 mils) (width 6 mils))
		(line (pt 230 mils -20 mils) (pt 230 mils 20 mils) (width 6 mils))
		(line (pt 230 mils 80 mils) (pt 230 mils 120 mils) (width 6 mils))
		(arc (pt 250 mils 100 mils) (radius 150 mils) (startAngle 0) (sweepAngle 360) (width 10  mils))
		(poly (pt 230 mils 100 mils) (pt 270 mils 120 mils) (pt 270 mils 80 mils) (pt 230 mils 100 mils) (width 10  mils))
		(attr "RefDes" "RefDes" (pt 450 mils 150 mils) (justify Left) (isVisible True) (textStyleRef "Default"))

	)
	(compDef "BSS138" (originalName "BSS138") (compHeader (numPins 3) (numParts 1) (refDesPrefix Q)
		)
		(compPin "1" (pinName "G") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "2" (pinName "S") (partNum 1) (symPinNum 3) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "3" (pinName "D") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "BSS138"))
		(attachedPattern (patternNum 1) (patternName "SOT95P240X120-3N")
			(numPads 3)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
				(padNum 3) (compPinRef "3")
			)
		)
		(attr "Manufacturer_Name" "onsemi")
		(attr "Manufacturer_Part_Number" "BSS138")
		(attr "Mouser Part Number" "512-BSS138")
		(attr "Mouser Price/Stock" "https://www.mouser.co.uk/ProductDetail/ON-Semiconductor-Fairchild/BSS138?qs=HK%252BeIG1iaahCeqBvjB4arg%3D%3D")
		(attr "Arrow Part Number" "BSS138")
		(attr "Arrow Price/Stock" "https://www.arrow.com/en/products/bss138/on-semiconductor")
		(attr "Mouser Testing Part Number" "")
		(attr "Mouser Testing Price/Stock" "")
		(attr "Description" "N-channel MOSFET,BSS138 0.2A 50V")
		(attr "Datasheet Link" "https://www.onsemi.com/pub/Collateral/BSS138-D.PDF")
		(attr "Height" "1.2 mm")
	)

)
