# makelife-firmware

Repository firmware embarque FineFab (ESP32 et toolchain associee).

## Role
- Maintenir les firmwares et tests natifs.
- Standardiser build, test et publication firmware.
- Integrer la couche de livraison dans la CI.

## Stack
- C++
- PlatformIO
- Unity (tests)

## Structure cible
- `src/`: code firmware
- `test/`: tests unitaires Unity
- `platformio.ini`: configuration build

## Demarrage rapide
```bash
pio run
pio test -e native
```

## Roadmap immediate
- Finaliser migration depuis `Kill_LIFE/firmware`.
- Ajouter couverture tests par module.
- Industrialiser pi- Industrialiser pi- Industrialiser pi- Industrialiser pi- Industrialiser pi- Industrialiser pi- Industrialiser pi- Industrialiser pi- Industrialiser pi- Industrialiser pi- Industrialiser pi- Industrialiser pi- Industrialiser pi- Industrialiser pi- Industrialiser pi- Industrialiser pi- Industrialiser pi- Industrialiser pi- Industrialiser pi- Industrialiser pi- Industrialiser pi- Indusrdware/`: projets et blocs KiCad
- `spice/`: simulations
- `tools/`: exports et automatisation

## Demarrage rapide
```bash
# Exemple (selon outillage local)
python -m pip install -r requirements.txt 2>/dev/null || true
```

## Roadmap immediate
- Mettre en place BaseMCPServer commune.
- Uniformiser exports KiBot/DRC/ERC.
- Publier evidence packs hardware.
