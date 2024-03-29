//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file DetectorConstruction.hh
/// \brief Definition of the DetectorConstruction class
//
// $Id: DetectorConstruction.hh 98748 2016-08-09 13:42:11Z gcosmo $
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "G4Material.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4Cache.hh"
#include "globals.hh"
#include "G4Box.hh"
#include "G4Ellipsoid.hh"
#include "G4Tubs.hh"
#include "G4OpticalSurface.hh"


class G4LogicalVolume;
class G4Material;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
  
    DetectorConstruction();
   ~DetectorConstruction();

  virtual G4VPhysicalVolume* Construct();
  
    G4LogicalVolume* Get_PMT_log_vol() const { return PMT_log_vol; }

    G4LogicalVolume* Get_Tank_log_vol() const { return Tank_log_vol; }

    G4LogicalVolume* Get_Air_log_vol() const { return Air_log_vol; }

  protected:

    // *** Logical Volume ***
    G4LogicalVolume* Tank_log_vol;    // pointer to the logical Det
    G4LogicalVolume* PMT_log_vol;
    G4LogicalVolume* Air_log_vol;
  
  private:
  
     // -----------------
     // *** Materials ***
     //------------------
     G4Material* fAir;
     G4Material* fParaffin;
     G4Material* fStainlessSteel;
     G4Material* fWater;
     G4Material* H2O; 
     G4Material* fGlass;
     G4Material* fVoid;
     G4Material* fSoil;
     G4Material* SaltWater;

  
     // *** Geometry ***
     //
     G4Ellipsoid* Pmt;

  


  private:
    
     void               DefineMaterials();
     G4VPhysicalVolume* ConstructVolumes();     
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

