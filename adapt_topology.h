#include "adapt_geometry.h"
#include "adapt_partition.h"
#include "adapt_geometry.h"
#include "adapt_compute.h"

#ifndef ADAPT_TOPOLOGY_H
#define ADAPT_TOPOLOGY_H

using namespace std;

class Mesh_Topology {
    public:
        Mesh_Topology(){};
        Mesh_Topology(Partition* Pa, Array<int>* ifn_in, std::map<int,double> U, int* bnd_map, int nBnd, MPI_Comm comm);
        std::map<int,vector<Vec3D*> > getNormals();
        std::map<int,vector<Vec3D*> > getRvectors();
        std::map<int,vector<Vec3D*> > getdXfXc();
        std::map<int,vector<double> > getdr();
        std::map<int,vector<double> > getdS();
        Array<int>* getIFN();
        std::map<int,double> getVol();
        std::vector<double> ReduceUToVertices(Array<double>* Uelem);
        std::map<int,int> getFace2Ref();
        std::map<int,std::vector<int> > getRef2Face();
        std::map<int,int> getVert2Ref();
        std::map<int,std::vector<int> > getRef2Vert();
    private:
        Array<double>* cc;
        std::map<int,vector<Vec3D*> > normals;
        std::map<int,vector<Vec3D*> > rvector;
        std::map<int,vector<Vec3D*> > dxfxc;
        std::map<int,vector<double> > dr;
        std::map<int,vector<double> > dS;
        std::map<int,double> Vol;
        Partition* P;
        Array<int>* ifn;
        std::map<int,int> face2ref;
        std::map<int,std::vector<int> > ref2face;
        std::map<int,int> vert2ref;
        std::map<int,std::vector<int> > ref2vert;
        MPI_Comm c;
};


#endif
