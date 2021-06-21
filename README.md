zum clonen: `git clone --recurse-submodules git@github.com:Patsch36/Hackathon_Quoridor.git`

# Hackathon_Quoridor

- git submodule update --init --recursive

## Changes
Alle wichtigen Änderungen in den bereits gegebenen Dateien können im [Wiki](https://github.com/Patsch36/Hackathon_Quoridor/wiki/Change-History) nachgelesen werden.

## Info für die Studenten:
ihr dürft alles benutzen, was ihr bekommt. Ihr dürft auch alles ändern, was ihr bekommt, das Spielfeld, den Graphen usw. Es sind alles Vorschläge bzw. der Weg wie wir es implementiert haben, aber nicht der einzige und vielleicht auch nicht der beste Weg. Die Klassen in der GameLib sind unvollständig und sollten ergänzt werden, die Klassen in der Graph und LoggerLibrary sind so vollständig, wie wir sie für unsere Implementierung am Ende hatten. Dass die vorhandene Funktionalität uns gereicht hat, heißt natürlich nicht, dass sie euch auch zwingend reicht und auch nicht, dass ihr alles davon benötigt. Nutzt einfach das, was ihr braucht und fügt das hinzu, was euch fehlt. 

Ihr bekommt von uns:
- Ein Spielfeld, bestehend aus 9x9 Feldern
- Einen Graphen, bestehend aus Vertices (den Feldern) und Edges (den Verbindungen zwischen den Feldern)
- Eine Klasse, die die Breitensuche auf dem Graphen implementiert
- Einen ConsoleUtils-Namespace, der euch die Konsoleninteraktion erleichtern soll
- Eine Loggerklasse, die euch bei der Entwicklung helfen kann.

## Clang tidy und clang format

clang tidy ist ein static analyzer tool, damit kann man schlechten code style finden. Bitte benutzt das. für visual studio gibt es [hier eine anleitung](https://docs.microsoft.com/en-us/cpp/code-quality/clang-tidy?view=msvc-160)

clang format ist ein formater tool, dass den Code automatisch formatieren kann dass der code egal von wem geschrieben immer im gleichen style ist. in visual studio [gibt es hier eine anleitung.](https://devblogs.microsoft.com/cppblog/clangformat-support-in-visual-studio-2017-15-7-preview-1/)

wer visual studio code benutzt sollte sich die clangd extension anschauen. in clion sollte alles automatisch gehen und bei anderen IDEs habe ich keine ahnung, da müsst ihr selber was finden.
